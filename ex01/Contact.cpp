#include "Contact.hpp"
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;

const size_t MAX_COLUMN_LENGTH = 10;
static const string names[] = {"First Name", "Last Name", "Nickname",
                               "Phone Number", "Darkest Secret"};

static string truncateColumn(const string& column) {
  if (column.length() > MAX_COLUMN_LENGTH)
    return column.substr(0, MAX_COLUMN_LENGTH - 1) + ".";
  else
    return column;
}

bool Contact::isValid() const {
  return !m_firstName.empty() && !m_lastName.empty() && !m_nickname.empty() &&
         !m_phoneNumber.empty() && !m_darkestSecret.empty();
}

void Contact::printRow(const size_t size, const string columns[]) const {
  if (not isValid())
    return;
  for (size_t i = 0; i < size - 1; i++)
    cout << std::setw(MAX_COLUMN_LENGTH) << truncateColumn(columns[i]) << "|";
  cout << std::setw(MAX_COLUMN_LENGTH) << truncateColumn(columns[size - 1])
       << endl;
}

void Contact::printHeader() const {
  printRow(4, names);
}

void Contact::printSimple() const {
  const string columns[] = {m_firstName, m_lastName, m_nickname,
                             m_phoneNumber};
  printRow(4, columns);
}

void Contact::printFull() const {
  if (not isValid())
    return;
  const string arr[] = {m_firstName, m_lastName, m_nickname, m_phoneNumber,
                         m_darkestSecret};
  for (size_t i = 0; i < 5; i++)
    cout << names[i] << ": " << arr[i] << endl;
}
