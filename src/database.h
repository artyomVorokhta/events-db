#pragma once

#include <functional>
#include <map>
#include <ostream>
#include <string>
#include <vector>

#include "date.h"

using Predicate =
    std::function<bool(const Date& date, const std::string& event)>;

class Database {
 public:
  void Add(const Date& date, const std::string& event);

  int RemoveIf(const Predicate& predicate);

  std::vector<std::string> FindIf(const Predicate& predicate) const;

  void Print(std::ostream& output) const;

  std::string Last(const Date& date) const;

 private:
  std::map<Date, std::vector<std::string>> events_by_dates_;
};
