#include "Phoney.hpp"

PhoneBook::PhoneBook() {
  m_size = 0;
}

PhoneBook::~PhoneBook() {
  cout << "Byeeeeee" << endl;
}

void PhoneBook::addContact(void) {
  Contact& contact = _contacts[m_size];
  cout << "Enter first name: ";
  cin >> contact.m_firstName;
  cout << "Enter last name: ";
  cin >> contact.m_lastName;
  cout << "Enter nickname: ";
  cin >> contact.m_nickname;
  cout << "Enter phone number: ";
  cin >> contact.m_phoneNumber;
  cout << "Enter darkest secret: ";
  cin >> contact.m_darkestSecret;
  m_size++;
}

Contact& PhoneBook::operator[](size_t index) {
  return _contacts[index];
}