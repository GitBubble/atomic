#ifndef HIVA_BASE_ATOMIC_RW_LOCK_H_
#define HIVA_BASE_ATOMIC_RW_LOCK_H_

#include <stdint.h>
#include <unistd.h>
#include <atomic>
//#include <iostream>

namespace hiva {
namespace base {

class ReadLockGuard;
class WriteLockGuard;


class AtomicRWLock {
  friend class ReadLockGuard;
  friend class WriteLockGuard;

 public:
  AtomicRWLock() {}
  explicit AtomicRWLock(bool write_first) : write_first_(write_first) {}

 private:
  // all these function only can used by ReadLockGuard/WriteLockGuard;
  void ReadLock();
  void WriteLock();

  void ReadUnlock();
  void WriteUnlock();

  AtomicRWLock(const AtomicRWLock&) = delete;
  AtomicRWLock& operator=(const AtomicRWLock&) = delete;
  std::atomic<uint32_t> write_lock_wait_num_ = {0};
  std::atomic<int32_t> lock_num_ = {0};
  bool write_first_ = true;
};

class ReadLockGuard {
 public:
  explicit ReadLockGuard(AtomicRWLock& lock) : rw_lock_(lock) {
    rw_lock_.ReadLock();
  }

  ~ReadLockGuard() { rw_lock_.ReadUnlock(); }

 private:
  ReadLockGuard(const ReadLockGuard& other) = delete;
  ReadLockGuard& operator=(const ReadLockGuard& other) = delete;
  AtomicRWLock& rw_lock_;
};

class WriteLockGuard {
 public:
  explicit WriteLockGuard(AtomicRWLock& lock) : rw_lock_(lock) {
    rw_lock_.WriteLock();
  }

  ~WriteLockGuard() { rw_lock_.WriteUnlock(); }

 private:
  WriteLockGuard(const WriteLockGuard& other) = delete;
  WriteLockGuard& operator=(const WriteLockGuard& other) = delete;
  AtomicRWLock& rw_lock_;
};

inline void AtomicRWLock::ReadLock() {

  uint32_t retry_times = 0;
  int32_t lock_num = lock_num_.load();
  if (write_first_) {
    do {
      while (lock_num < 0 || write_lock_wait_num_.load() > 0) {
        if (++retry_times == 5) {
          // saving cpu
          retry_times = 0;
        }
        lock_num = lock_num_.load();
      }
    } while (!lock_num_.compare_exchange_weak(lock_num, lock_num + 1,
                                              std::memory_order_acquire,
                                              std::memory_order_relaxed));
  } else {
    do {
      while (lock_num < 0) {
        if (++retry_times == 5) {
          // saving cpu
          retry_times = 0;
        }
        lock_num = lock_num_.load();
      }
    } while (!lock_num_.compare_exchange_weak(lock_num, lock_num + 1,
                                              std::memory_order_acquire,
                                              std::memory_order_relaxed));
  }
}

inline void AtomicRWLock::WriteLock() {
  //auto this_thread_id = std::this_thread::get_id();
    lock_num_.fetch_sub(1);
  int32_t rw_lock_free = 0;
  uint32_t retry_times = 0;
  write_lock_wait_num_.fetch_add(1);
  while (!lock_num_.compare_exchange_weak(rw_lock_free, -1,
                                          std::memory_order_acquire,
                                          std::memory_order_relaxed)) {
    // rw_lock_free will change after CAS fail, so init agin
    rw_lock_free = 0;
    if (++retry_times == 5) {
      // saving cpu
      retry_times = 0;
    }
  }
  write_lock_wait_num_.fetch_sub(1);
}

inline void AtomicRWLock::ReadUnlock() {
  lock_num_.fetch_sub(1);
}

inline void AtomicRWLock::WriteUnlock() {
  if (lock_num_.fetch_add(1) == -1) {
//    write_thread_id_ = NULL_THREAD_ID;
  }
}

}  // namespace base
}  // namespace hiva


int main()
{

  hiva::base::AtomicRWLock rw_lock(false);
  //auto start = hiva::utility::Time::MonoTime();
  for (int i = 0; i < 1000000; ++i) {
    hiva::base::WriteLockGuard lg(rw_lock);
  } 
  //auto end = hiva::utility::Time::MonoTime();
  //std::cout << "rw lock 1000000 times: " << end - start << std::endl;
    return 0;

}


#endif  // HIVA_BASE_ATOMIC_RW_LOCK_H_
