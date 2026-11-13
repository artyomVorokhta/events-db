#pragma once

#include <iostream>
#include <map>
#include <sstream>

class Date {
 public:
  Date(const int year, const int month, const int day);

  int GetYear() const { return year_; }

  int GetMonth() const { return month_; }

  int GetDay() const { return day_; }

 private:
  int year_, month_, day_;

  static constexpr int kMinYear = 0;
  static constexpr int kMaxYear = 9999;
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);
