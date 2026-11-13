#pragma once

#include <memory>

#include "comparison.h"
#include "date.h"
#include "logical_operation.h"

class Node {
 public:
  virtual ~Node() = default;

  virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
 public:
  bool Evaluate(const Date&, const std::string&) const override {
    return true;
  };
};

class DateComparisonNode : public Node {
 public:
  DateComparisonNode(const Comparison cmp, const Date& date);

  bool Evaluate(const Date& date, const std::string& event) const override;

 private:
  const Comparison cmp_;
  const Date date_;
};

class EventComparisonNode : public Node {
 public:
  EventComparisonNode(const Comparison cmp, const std::string& event);

  bool Evaluate(const Date& date, const std::string& event) const override;

 private:
  const Comparison cmp_;
  const std::string event_;
};

class LogicalOperationNode : public Node {
 public:
  LogicalOperationNode(const LogicalOperation op,
                       const std::shared_ptr<Node>& left,
                       const std::shared_ptr<Node>& right);

  bool Evaluate(const Date& date, const std::string& event) const override;

 private:
  const LogicalOperation op_;
  const std::shared_ptr<Node> left_, right_;
};
