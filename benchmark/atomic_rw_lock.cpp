#include "atomic_rw_lock.h"
#include <atomic>
#include <mutex>
#include <string>
#include "time.h"

volatile bool ready = false;

int main(int argc, char const *argv[]) {
  if (argc != 5) {
    std::cout << "Usage:" << std::endl;
    std::cout << "     argv[0] program name" << std::endl;
    std::cout << "     argv[1] reader num" << std::endl;
    std::cout << "     argv[2] writer num" << std::endl;
    std::cout << "     argv[3] read lock times" << std::endl;
    std::cout << "     argv[4] write lock times" << std::endl;
    return 0;
  }

  hiva::base::AtomicRWLock rw_lock(false);
  std::mutex mutex;
  auto start = hiva::utility::Time::MonoTime();
  for (int i = 0; i < 1000000; ++i) {
    hiva::base::WriteLockGuard lg(rw_lock);
  }
  auto end = hiva::utility::Time::MonoTime();
  std::cout << "rw lock 1000000 times: " << end - start << std::endl;

  start = hiva::utility::Time::MonoTime();
  for (int i = 0; i < 1000000; ++i) {
    std::lock_guard<std::mutex> lg(mutex);
  }
  end = hiva::utility::Time::MonoTime();
  std::cout << "std lock 1000000 times: " << end - start << std::endl;

  int reader_num = std::stoi(argv[1]);
  int writer_num = std::stoi(argv[2]);
  int read_lock_times = std::stoi(argv[3]);
  int write_lock_times = std::stoi(argv[4]);
 
  std::atomic<int> count = {0};
  uint64_t value = 0;
  std::thread readers[reader_num];
  std::thread writers[writer_num];

  for (int i = 0; i < reader_num; ++i) {
    readers[i] = std::thread([&]() {
      while (!ready) {
        asm volatile("yield" ::: "memory");
      }
      for (int j = 0; j < read_lock_times; j++) {
        hiva::base::ReadLockGuard lg(rw_lock);
        usleep(1);
      }
      count++;
    });
  }

  for (int i = 0; i < writer_num; ++i) {
    writers[i] = std::thread([&]() {
      while (!ready) {
        asm volatile("yield" ::: "memory");
      }
      for (int j = 0; j < write_lock_times; j++) {
        hiva::base::WriteLockGuard lg(rw_lock);
        usleep(1);
      }
      count++;
    });
  }
  sleep(1);
  ready = true;
  start = hiva::utility::Time::MonoTime();
  while (count < reader_num + writer_num) {
    continue;
  }
  end = hiva::utility::Time::MonoTime();
  std::cout << "atomic rw lock : " << reader_num << " readers and "
            << writer_num << " writers each lock 10000 times: " << end - start
            << std::endl;
  for (int i = 0; i < reader_num; ++i) {
    readers[i].join();
  }

  for (int i = 0; i < writer_num; ++i) {
    writers[i].join();
  }

  ready = false;
  count.store(0);
  for (int i = 0; i < reader_num; ++i) {
    readers[i] = std::thread([&]() {
      while (!ready) {
        asm volatile("yield" ::: "memory");
      }
      for (int j = 0; j < read_lock_times; j++) {
        std::lock_guard<std::mutex> lock(mutex);
        usleep(1);
      }
      count++;
    });
  }

  for (int i = 0; i < writer_num; ++i) {
    writers[i] = std::thread([&]() {
      while (!ready) {
        asm volatile("yield" ::: "memory");
      }
      for (int j = 0; j < write_lock_times; j++) {
        std::lock_guard<std::mutex> lock(mutex);
        usleep(1);
      }
      count++;
    });
  }
  sleep(1);
  ready = true;
  start = hiva::utility::Time::MonoTime();
  while (count < reader_num + writer_num) {
    continue;
  }
  end = hiva::utility::Time::MonoTime();
  std::cout << "standard lock : " << reader_num << " readers and " << writer_num
            << " writers each lock 10000 times: " << end - start << std::endl;
  for (int i = 0; i < reader_num; ++i) {
    readers[i].join();
  }

  for (int i = 0; i < writer_num; ++i) {
    writers[i].join();
  }

  return 0;
}
