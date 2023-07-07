#ifndef __CALC_H__
#define __CALC_H__

#include "calc_step.h"
#include "logger.h"
#include <list>
#include <map>
#include <ostream>

namespace ModernCppCI {
template <class Type> using Dictionary = std::map<std::string, Type>;
namespace DefaultOperations {
const Operation Plus = [](const int &value1, const int &value2) {
  return value1 + value2;
};
const Operation Minus = [](const int &value1, const int &value2) {
  return value1 - value2;
};
const Operation Times = [](const int &value1, const int &value2) {
  return value1 * value2;
};
const Operation Div = [](const int &value1, const int &value2) {
  return value1 / value2;
};
const Operation Zero = [](const int &value1, const int &value2) { return 0; };
} // namespace DefaultOperations
class Calc {
public:
  Calc() noexcept {};
  Calc(const Calc &other) noexcept
      : operations_(other.operations_), steps_{other.steps_} {}
  Calc &operator=(const Calc &other) noexcept;
  auto total_operations() const noexcept { return operations_.size(); }
  void add_step(const CalcStep &step);
  void add_step(const int value);
  void add_step(const std::string &operation_name);
  auto total_steps() const noexcept { return steps_.size(); }
  int result() const;

  template <typename T> Calc operator<<(const T &value) const {
    Calc new_calc{*this};
    new_calc.add_step(value);
    return new_calc;
  }

  friend std::ostream &operator<<(std::ostream &stream, const Calc &calc);

private:
  std::list<CalcStep> steps_{};
  Dictionary<Operation> operations_{{"+", DefaultOperations::Plus},
                                    {"-", DefaultOperations::Minus},
                                    {"*", DefaultOperations::Times},
                                    {"/", DefaultOperations::Div}};
  static Logger logger_;
};
} // namespace ModernCppCI

#endif /* __CALC_H__ */
