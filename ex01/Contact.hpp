#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>
#include <string>
#include "Counter.hpp"

using std::cout;
using std::endl;
using std::string;

struct Entry {
  string firstName;
  string lastName;
  string nickname;
  string phoneNumber;
  string darkestSecret;
};

class Contact {
 private:
  static const size_t CONTACT_SIZE = 8;

  CycleCounter m_counter;
  Entry m_entry[CONTACT_SIZE];

  void printEntryAt(const size_t index) const;

 public:
  Contact() : m_counter(CONTACT_SIZE){};
  void addContact(Entry entry);
  void printContact() const;
  // void printEntryAt(size_t index) const;
};

#endif  // __CONTACT_H__