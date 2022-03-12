#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include "Util.hpp"

using std::cout;

const size_t NUM_ELEMENTS = 5;

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
