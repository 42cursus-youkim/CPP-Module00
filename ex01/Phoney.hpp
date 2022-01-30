#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

const size_t MAX_CONTACTS = 8;

class Contact {
 public:
  string m_firstName;
  string m_lastName;
  string m_nickname;
  string m_phoneNumber;
  string m_darkestSecret;

  Contact();
  Contact(string firstName,
          string lastName,
          string nickname,
          string phoneNumber,
          string darkestSecret);
};

ostream& operator<<(ostream& os, const Contact& contact);

class PhoneBook {
 private:
  Contact _contacts[MAX_CONTACTS];
  size_t m_size;

 public:
  PhoneBook();
  ~PhoneBook();
  void addContact(void);
  Contact& operator[](size_t index);
  const Contact& operator[](size_t index) const;
  // void printContact(void);
  // void searchContact(string name);
  // void printContacts();
};

ostream& operator<<(ostream& os, const PhoneBook& phoneBook);