#ifndef HIVA_TIME_TIME_H_
#define HIVA_TIME_TIME_H_

#include <limits>
#include <string>
#include "duration.h"

namespace hiva {
namespace utility {

class Time {
 public:
  static const Time MAX;
  static const Time MIN;
  Time() {}
  explicit Time(uint64_t nanoseconds);
  explicit Time(int nanoseconds);
  explicit Time(double seconds);
  Time(uint32_t seconds, uint32_t nanoseconds);
  Time(const Time& other);
  Time& operator=(const Time& other);
  ~Time() {}

  static Time Now();
  static Time MonoTime();
  static void SleepUntil(const Time& time);

  double ToSecond() const;
  uint64_t ToNanosecond() const;
  std::string ToString() const;
  bool IsZero() const;

  Duration operator-(const Time& rhs) const;
  Time operator+(const Duration& rhs) const;
  Time operator-(const Duration& rhs) const;
  Time& operator+=(const Duration& rhs);
  Time& operator-=(const Duration& rhs);
  bool operator==(const Time& rhs) const;
  bool operator!=(const Time& rhs) const;
  bool operator>(const Time& rhs) const;
  bool operator<(const Time& rhs) const;
  bool operator>=(const Time& rhs) const;
  bool operator<=(const Time& rhs) const;

 private:
  uint64_t nanoseconds_ = 0;
};

std::ostream& operator<<(std::ostream& os, const Time& rhs);

}  // namespace hiva
}  // namespace utility

#endif  // HIVA_TIME_TIME_H_
