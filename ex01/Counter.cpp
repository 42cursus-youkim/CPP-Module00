#include "Counter.hpp"

void Counter::increment() {
  if (m_value >= m_max_value)
    m_value = 0;
  else
    m_value++;
}

size_t Counter::getValue() {
  return m_value;
}
