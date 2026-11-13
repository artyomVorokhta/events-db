#include "database.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "date.h"

void Database::Add(const Date& date, const std::string& event) {
  std::vector<std::string>& events = events_by_dates_[date];

  const auto it = std::find(events.begin(), events.end(), event);

  if (it == events.end()) {
    events.push_back(event);
  }
}

int Database::RemoveIf(const Predicate& predicate) {
  int count = 0;

  for (auto date_it = events_by_dates_.begin();
       date_it != events_by_dates_.end();) {
    std::vector<std::string>& events = date_it->second;

    const size_t old_size = events.size();

    const auto event_remove_it = std::remove_if(
        events.begin(), events.end(), [&](const std::string& event) {
          return predicate(date_it->first, event);
        });

    if (event_remove_it != events.end()) {
      events.erase(event_remove_it, events.end());
    }

    count += old_size - events.size();

    if (events.empty()) {
      date_it = events_by_dates_.erase(date_it);
    } else {
      ++date_it;
    }
  }

  return count;
}

std::vector<std::string> Database::FindIf(const Predicate& predicate) const {
  std::vector<std::string> result;

  for (auto date_it = events_by_dates_.begin();
       date_it != events_by_dates_.end();) {
    const Date& date = date_it->first;
    const std::vector<std::string>& events = date_it->second;

    const auto matches = [&](const std::string& event) {
      return predicate(date, event);
    };

    for (auto event_it = std::find_if(events.begin(), events.end(), matches);
         event_it != events.end();) {
      std::stringstream ss;
      ss << date << ' ' << *event_it;

      result.push_back(ss.str());

      event_it = std::find_if(++event_it, events.end(), matches);
    }

    ++date_it;
  }

  return result;
}

void Database::Print(std::ostream& output) const {
  for (const auto& [date, events] : events_by_dates_) {
    for (const std::string& event : events) {
      output << date << ' ' << event << '\n';
    }
  }
}

std::string Database::Last(const Date& date) const {
  auto it = events_by_dates_.upper_bound(date);

  if (it != events_by_dates_.begin()) {
    --it;
    std::stringstream ss;
    ss << it->first << ' ' << it->second.back();

    return ss.str();
  }

  throw std::invalid_argument("No entries");
}
