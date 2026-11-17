#pragma once

#include <sstream>

#include "date.h"

Date ParseDate(std::istringstream& stream); // можно std::istream, чтобы иметь возможность передавать не только строковый поток

void TestParseDate();
