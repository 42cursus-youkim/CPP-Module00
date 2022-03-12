#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include "Counter.hpp"

using std::string;

const string names[] = {"First Name", "Last Name", "Nickname", "Phone Number",
                        "Darkest Secret"};

class Contact {
 public:
  string m_firstName;
  string m_lastName;
  string m_nickname;
  string m_phoneNumber;
  string m_darkestSecret;

  bool isValid() const;
  void print() const;
};

#endif  // __CONTACT_H__