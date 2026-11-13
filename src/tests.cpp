#include "tests.h"

#include "condition_parser.h"
#include "date_parser.h"
#include "event_parser.h"
#include "test_runner.h"

void TestAll() {
  TestRunner tr;
  tr.RunTest(TestParseEvent, "TestParseEvent");
  tr.RunTest(TestParseDate, "TestParseDate");
  tr.RunTest(TestParseCondition, "TestParseCondition");
}
