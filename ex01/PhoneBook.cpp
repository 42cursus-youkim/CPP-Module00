#include "PhoneBook.hpp"
#include <stdexcept>

void PhoneBook::addContact(Contact entry) {
  const size_t index = m_counter.getValue();

  m_contacts[index] = entry;
  m_counter.increment();
}

Contact& PhoneBook::getContactAt(const size_t index) {
  if (not m_counter.indexInRange(index))
    throw std::out_of_range("Index out of range");

  return m_contacts[index];
}
