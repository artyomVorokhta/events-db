#include "date_parser.h"

#include <sstream>

#include "test_runner.h"

void TestParseDate() {
  {
    std::istringstream is("2026-11-11");
    AssertEqual(ParseDate(is), Date(2026, 11, 11), "Parse date 1");
  }
  {
    std::istringstream is("0-2-31");
    AssertEqual(ParseDate(is), Date(0, 2, 31), "Parse date 2");
  }
}
