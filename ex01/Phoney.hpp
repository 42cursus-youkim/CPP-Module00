#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ostream;
using std::string;

const size_t MAX_CONTACTS = 8;
const size_t FIELD_WIDTH = 10;

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
  size_t m_current;
  Contact _contacts[MAX_CONTACTS];

  void editContact(size_t index);
  // Contact& operator[](size_t index);
  void formattedCell(string str);
  void printContact(size_t index);

 public:
  PhoneBook();
  ~PhoneBook();
  void addContact(void);
  string formattedLine(size_t index);
  // const Contact& operator[](size_t index) const;
  void printContacts(void);
  // void searchContact(string name);
  // void printContacts();
};

// ostream& operator<<(ostream& os, const PhoneBook& phoneBook);