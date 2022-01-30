#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

struct Contact {
 public:
  string m_firstName;
  string m_lastName;
  string m_nickname;
  string m_phoneNumber;
  string m_darkestSecret;

  Contact(string firstName,
          string lastName,
          string nickname,
          string phoneNumber,
          string darkestSecret);
};

class PhoneBook {
 private:
  Contact _contacts[8];
  size_t m_size;

 public:
  PhoneBook();
  ~PhoneBook();
  void addContact(Contact contact);
  void searchContact(string name);
  void printContacts();
};