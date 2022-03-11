#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <iostream>

class CycleCounter {
 private:
  size_t m_value;
  size_t m_cycle_size;

 public:
  CycleCounter(const size_t cycle_size)
      : m_value(0), m_cycle_size(cycle_size){};
  void increment();
  size_t getValue();
};

#endif  // __COUNTER_H__