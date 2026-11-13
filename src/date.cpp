#include "date.h"

#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <tuple>

Date::Date(const int year, const int month, const int day)
    : year_(year), month_(month), day_(day) {
  if (year < kMinYear || year > kMaxYear)
    throw std::invalid_argument(
        "Year value must be more than " + std::to_string(kMinYear) +
        " or equal and less than " + std::to_string(kMaxYear) +
        " or equal: " + std::to_string(year));

  if (month < 1 || month > 12)
    throw std::invalid_argument("Month value is invalid: " +
                                std::to_string(month));

  if (day < 1 || day > 31)
    throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
}

bool operator<(const Date& lhs, const Date& rhs) {
  return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
         std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator==(const Date& lhs, const Date& rhs) {
  return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) ==
         std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs) { return !(lhs == rhs); }

bool operator>(const Date& lhs, const Date& rhs) { return rhs < lhs; }

bool operator>=(const Date& lhs, const Date& rhs) { return !(lhs < rhs); }

bool operator<=(const Date& lhs, const Date& rhs) { return !(rhs < lhs); }

std::ostream& operator<<(std::ostream& stream, const Date& date) {
  stream << std::setw(4) << std::setfill('0') << date.GetYear() << '-'
         << std::setw(2) << std::setfill('0') << date.GetMonth() << '-'
         << std::setw(2) << std::setfill('0') << date.GetDay();
  return stream;
}
