#pragma once

#include <istream>
#include <string>

#include "trim.h"

inline std::string ParseEvent(std::istream& is) {
  std::string line;
  std::getline(is, line);

  return Ltrim(line);
}

void TestParseEvent();
