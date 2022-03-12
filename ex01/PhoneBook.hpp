#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {
 private:
  static const size_t CONTACT_SIZE = 8;
  void addContact(Contact entry);

  CycleCounter m_counter;
  Contact m_contacts[CONTACT_SIZE];

  void printCell(const string& cell) const;
  void printCellLast(const string& cell) const;
  void printRow(const size_t index, const Contact& contact) const;
  void printHeader() const;

 public:
  PhoneBook();
  void addContactFromInput();
  Contact& getContactAt(const size_t index);
  void printContacts() const;
};

#endif  // __PHONEBOOK_H__