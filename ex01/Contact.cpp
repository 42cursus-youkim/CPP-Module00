#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include "Util.hpp"

using std::cout;

const size_t NUM_ELEMENTS = 5;

// constructor
Contact::Contact()
    : m_firstName(""),
      m_lastName(""),
      m_nickname(""),
      m_phoneNumber(""),
      m_darkestSecret("") {}

Contact::Contact(const string& firstName,
                 const string& lastName,
                 const string& nickname,
                 const string& phoneNumber,
                 const string& darkestSecret)
    : m_firstName(firstName),
      m_lastName(lastName),
      m_nickname(nickname),
      m_phoneNumber(phoneNumber),
      m_darkestSecret(darkestSecret) {}

bool Contact::isValid() const {
  return !m_firstName.empty() && !m_lastName.empty() && !m_nickname.empty() &&
         !m_phoneNumber.empty() && !m_darkestSecret.empty();
}

void Contact::print() const {
  if (not isValid())
    return;
  const string arr[] = {m_firstName, m_lastName, m_nickname, m_phoneNumber,
                        m_darkestSecret};
  for (size_t i = 0; i < NUM_ELEMENTS; i++)
    cout << names[i] << ": " << arr[i] << "\n";
}

// getters
const string& Contact::getFirstName() const {
  return m_firstName;
}
const string& Contact::getLastName() const {
  return m_lastName;
}
const string& Contact::getNickname() const {
  return m_nickname;
}
const string& Contact::getPhoneNumber() const {
  return m_phoneNumber;
}
const string& Contact::getDarkestSecret() const {
  return m_darkestSecret;
}
