#include "Counter.hpp"

void CycleCounter::increment() {
  m_value++;
  if (m_value == m_cycle_size)
    m_value = 0;
}

size_t CycleCounter::getValue() const {
  return m_value;
}

size_t CycleCounter::getCycleSize() const {
  return m_cycle_size;
}

bool CycleCounter::indexInRange(const size_t index) const {
  return index < getCycleSize();
}