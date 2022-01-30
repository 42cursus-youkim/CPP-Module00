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
  os << "First name: " << contact.m_firstName << " ";
  os << "Last name: " << contact.m_lastName << " ";
  os << "Nickname: " << contact.m_nickname << " ";
  os << "Phone number: " << contact.m_phoneNumber << " ";
  os << "Darkest secret: " << contact.m_darkestSecret << endl;
  return os;
}