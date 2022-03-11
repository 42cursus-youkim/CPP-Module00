#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using std::string;

struct Entry {
  string firstName;
  string lastName;
  string nickname;
  string phoneNumber;
  string darkestSecret;
};

const size_t CONTACT_SIZE = 8;
class Contact {
 private:
  Entry m_entry[CONTACT_SIZE];
};

#endif /* CONTACT_HPP */