#include "Counter.hpp"

void CycleCounter::increment() {
  m_value++;
  if (m_value == m_cycle_size)
    m_value = 0;
}

size_t CycleCounter::getValue() {
  return m_value;
}
