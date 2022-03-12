#include "Contact.hpp"
#include <iostream>

using std::cout;
using std::endl;

bool Contact::isValid() const {
  return !m_firstName.empty() && !m_lastName.empty() && !m_nickname.empty() &&
         !m_phoneNumber.empty() && !m_darkestSecret.empty();
}

void Contact::printSimple() const {
  if (not isValid())
    return;
  cout << m_firstName << " " << m_lastName << " " << m_nickname << " "
       << m_phoneNumber << endl;
}

void Contact::printFull() const {
  if (not isValid())
    return;
  cout << m_firstName << " " << m_lastName << " " << m_nickname << " "
       << m_phoneNumber << " " << m_darkestSecret << endl;
}