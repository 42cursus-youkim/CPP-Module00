#include "Contact.hpp"

void Contact::addContact(Entry entry) {
  const size_t index = m_counter.getValue();

  m_entry[index] = entry;
  m_counter.increment();
}

void Contact::printEntryAt(const size_t index) const {
  const Entry entry = m_entry[index];

  cout << entry.firstName << " " << entry.lastName << " " << entry.nickname
       << " " << entry.phoneNumber << " " << entry.darkestSecret << endl;
}

void Contact::printContact() const {
  
  for (size_t i = 0; i < m_counter.getCycleSize(); i++) {
    printEntryAt(i);
  }
}
