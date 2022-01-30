#include "Phonebook.hpp"

Contact::Contact(string firstName,
                 string lastName,
                 string nickname,
                 string phoneNumber,
                 string darkestSecret) {
  m_firstName = firstName;
  m_lastName = lastName;
  m_nickname = nickname;
  m_phoneNumber = phoneNumber;
  m_darkestSecret = darkestSecret;
};

