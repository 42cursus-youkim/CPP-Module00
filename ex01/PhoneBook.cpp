#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact entry) {
  const size_t index = m_counter.getValue();

  m_entry[index] = entry;
  m_counter.increment();
}

void PhoneBook::printEntryAt(const size_t index) const {
  const Contact entry = m_entry[index];

  cout << entry.firstName << " " << entry.lastName << " " << entry.nickname
       << " " << entry.phoneNumber << " " << entry.darkestSecret << endl;
}

void PhoneBook::printContact() const {
  for (size_t i = 0; i < m_counter.getCycleSize(); i++) {
    printEntryAt(i);
  }
}
