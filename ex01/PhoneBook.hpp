#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Counter.hpp"

using std::cout;
using std::endl;
using std::string;

class Contact {
 public:
  string firstName;
  string lastName;
  string nickname;
  string phoneNumber;
  string darkestSecret;
};

class PhoneBook {
 private:
  static const size_t CONTACT_SIZE = 8;

  CycleCounter m_counter;
  Contact m_entry[CONTACT_SIZE];

  void printEntryAt(const size_t index) const;

 public:
  PhoneBook() : m_counter(CONTACT_SIZE){};
  void addContact(Contact entry);
  void printContact() const;
  // void printEntryAt(size_t index) const;
};

#endif /* PHONEBOOK_HPP */