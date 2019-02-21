#ifndef HIVA_TIME_RATE_H_
#define HIVA_TIME_RATE_H_

#include "time.h"
#include "duration.h"

namespace hiva {
namespace utility {

class Rate {
 public:
  explicit Rate(double frequency);
  explicit Rate(uint64_t nanoseconds);
  explicit Rate(const Duration&);
  void Sleep();
  void Reset();
  Duration CycleTime() const;
  Duration ExpectedCycleTime() const { return expected_cycle_time_; }

 private:
  Time start_;
  Duration expected_cycle_time_;
  Duration actual_cycle_time_;
};

}  // namespace utility
}  // namespace hiva

#endif  // HIVA_TIME_RATE_H_
