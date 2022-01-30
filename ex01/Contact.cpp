#include "Phoney.hpp"

Contact::Contact()
    : m_firstName(""),
      m_lastName(""),
      m_nickname(""),
      m_phoneNumber(""),
      m_darkestSecret("") {}

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

ostream& operator<<(ostream& os, const Contact& contact) {
  os << "First Name: " << contact.m_firstName << endl;
  os << "Last Name: " << contact.m_lastName << endl;
  os << "Nickname: " << contact.m_nickname << endl;
  os << "Phone Number: " << contact.m_phoneNumber << endl;
  os << "Darkest Secret: " << contact.m_darkestSecret << endl;
  return os;
}