#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <iostream>

class Counter {
 private:
  size_t m_value;
  size_t m_max_value;

 public:
  Counter(size_t& counter, const size_t max_value)
      : m_value(counter), m_max_value(max_value){};
  void increment();
  size_t getValue();
};

#endif  // __COUNTER_H__