#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
 private:
  size_t m_current_idx;
  Contact m_contacts[8];

 public:
  PhoneBook();
  ~PhoneBook();
  void addContact();
  void printContacts();
};

#endif /* PHONEBOOK_HPP */