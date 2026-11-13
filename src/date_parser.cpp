#include "date_parser.h"

#include <sstream>

#include "date.h"

Date ParseDate(std::istringstream& stream) {
  std::string date_string;
  stream >> date_string;

  std::istringstream string_stream(date_string);

  int year, month, day;

  auto ignore_dash = [&string_stream]() {
    if (string_stream.get() != '-') string_stream.setstate(std::ios::failbit);
  };

  string_stream >> year;
  ignore_dash();
  string_stream >> month;
  ignore_dash();
  string_stream >> day;

  if (string_stream.fail() || !string_stream.eof())
    throw std::invalid_argument("Wrong date format: " + date_string);

  return Date(year, month, day);
};
