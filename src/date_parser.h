#pragma once

#include <sstream>

#include "date.h"

Date ParseDate(std::istringstream& stream);

void TestParseDate();
