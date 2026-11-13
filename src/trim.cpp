#include "trim.h"

#include <cstddef>
#include <string>

const std::string kWhitespace = " \n\r\t\f\v";

std::string Ltrim(const std::string& str) {
  const size_t start = str.find_first_not_of(kWhitespace);
  return start == std::string::npos ? "" : str.substr(start);
}

std::string Rtrim(const std::string& str) {
  const size_t end = str.find_last_not_of(kWhitespace);
  return end == std::string::npos ? "" : str.substr(0, end + 1);
}

std::string Trim(const std::string& str) { return Ltrim(Rtrim(str)); }
