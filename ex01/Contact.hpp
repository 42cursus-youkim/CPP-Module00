#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include "Counter.hpp"

using std::string;

const string names[] = {"First Name", "Last Name", "Nickname", "Phone Number",
                        "Darkest Secret"};

class Contact {
 private:
  string m_firstName;
  string m_lastName;
  string m_nickname;
  string m_phoneNumber;
  string m_darkestSecret;

 public:
  Contact();
  Contact(const string& firstName,
          const string& lastName,
          const string& nickname,
          const string& phoneNumber,
          const string& darkestSecret);

  bool isValid() const;
  void print() const;

  // meaningless getters and setters
  const string& getFirstName() const;
  const string& getLastName() const;
  const string& getNickname() const;
  const string& getPhoneNumber() const;
  const string& getDarkestSecret() const;
};

#endif  // __CONTACT_H__