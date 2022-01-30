#include "Phoney.hpp"

PhoneBook::PhoneBook() {
  m_current = 0;
}

PhoneBook::~PhoneBook() {
  cout << "Byeeeeee" << endl;
}

void PhoneBook::editContact(size_t index) {
  Contact& contact = _contacts[index];
  cout << "Enter first name: " << endl;
  std::getline(cin, contact.m_firstName);
  cout << "Enter last name: " << endl;
  std::getline(cin, contact.m_lastName);
  cout << "Enter nickname: " << endl;
  std::getline(cin, contact.m_nickname);
  cout << "Enter phone number: " << endl;
  std::getline(cin, contact.m_phoneNumber);
  cout << "Enter darkest secret: " << endl;
  std::getline(cin, contact.m_darkestSecret);
}

void PhoneBook::addContact(void) {
  editContact(m_current++);
  if (m_current == MAX_CONTACTS)
    m_current = 0;
}

// Contact& PhoneBook::operator[](size_t index) {
//   return _contacts[index];
// }

// const Contact& PhoneBook::operator[](size_t index) const {
//   return _contacts[index];
// }
void PhoneBook::formattedCell(string str) {
  string cell;

  if (str.length() > 10)
    cell = str.substr(0, 10) + '.';
  else
    cell = str;
  cout << std::setw(10) << cell << "|";
}

void PhoneBook::printContact(size_t index) {
  Contact& contact = _contacts[index];

  formattedCell(contact.m_firstName);
  formattedCell(contact.m_lastName);
  formattedCell(contact.m_nickname);
  formattedCell(contact.m_phoneNumber);
  formattedCell(contact.m_darkestSecret);
  cout << endl;
}

void PhoneBook::printContacts(void) {
  // formattedCell("first name");
  // formattedCell("last name");
  // formattedCell("nickname");
  // formattedCell("telephone");
  // formattedCell("D. Secret");
  // cout << endl;
  // cout << std::setfill('-') << std::setw(55) << "";
  // cout << std::setfill(' ') << endl;

  for (size_t i = 0; i < m_current; i++)
    printContact(i);
}

// ostream& operator<<(ostream& os, const PhoneBook& phoneBook) {
//   for (size_t i = 0; i < MAX_CONTACTS; i++) {
//     os << phoneBook.formattedLine(i);
//   }
//   os << endl;
//   return os;
// }