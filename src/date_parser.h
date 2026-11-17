#pragma once

#include <istream>

#include "date.h"

Date ParseDate(std::istream& stream);

void TestParseDate();
