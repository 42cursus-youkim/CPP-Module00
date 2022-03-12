#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
 private:
  static const size_t CONTACT_SIZE = 8;

  CycleCounter m_counter;
  Contact m_contacts[CONTACT_SIZE];

 public:
  PhoneBook() : m_counter(CONTACT_SIZE){};
  void addContact(Contact entry);
  Contact& getContactAt(const size_t index);
};

#endif /* PHONEBOOK_HPP */