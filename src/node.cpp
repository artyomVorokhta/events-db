#include "node.h"

#include <memory>

#include "comparison.h"
#include "date.h"
#include "logical_operation.h"

DateComparisonNode::DateComparisonNode(const Comparison cmp, const Date& date)
    : cmp_(cmp), date_(date) {};

bool DateComparisonNode::Evaluate(const Date& date, const std::string&) const {
  if (cmp_ == Comparison::Less) {
    return date < date_;
  } else if (cmp_ == Comparison::LessOrEqual) {
    return date <= date_;
  } else if (cmp_ == Comparison::Greater) {
    return date > date_;
  } else if (cmp_ == Comparison::GreaterOrEqual) {
    return date >= date_;
  } else if (cmp_ == Comparison::Equal) {
    return date == date_;
  } else if (cmp_ == Comparison::NotEqual) {
    return date != date_;
  }
  return false;
};

EventComparisonNode::EventComparisonNode(const Comparison cmp,
                                         const std::string& event)
    : cmp_(cmp), event_(event) {};

bool EventComparisonNode::Evaluate(const Date&,
                                   const std::string& event) const {
  if (cmp_ == Comparison::Less) {
    return event < event_;
  } else if (cmp_ == Comparison::LessOrEqual) {
    return event <= event_;
  } else if (cmp_ == Comparison::Greater) {
    return event > event_;
  } else if (cmp_ == Comparison::GreaterOrEqual) {
    return event >= event_;
  } else if (cmp_ == Comparison::Equal) {
    return event == event_;
  } else if (cmp_ == Comparison::NotEqual) {
    return event != event_;
  }
  return false;
};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation op,
                                           const std::shared_ptr<Node>& left,
                                           const std::shared_ptr<Node>& right)
    : op_(op), left_(left), right_(right) {};

bool LogicalOperationNode::Evaluate(const Date& date,
                                    const std::string& event) const {
  const bool left = left_->Evaluate(date, event);
  const bool right = right_->Evaluate(date, event);

  return op_ == LogicalOperation::Or ? (left || right) : (left && right);
};
