#include "Phonebook.hpp"

ostream& operator<<(ostream& os, const Contact& contact) {
  os << "First name: " << contact.m_firstName << " ";
  // os << "Last name: " << contact.m_lastName << " ";
  // os << "Nickname: " << contact.m_nickname << " ";
  // os << "Phone number: " << contact.m_phoneNumber << " ";
  // os << "Darkest secret: " << contact.m_darkestSecret << endl;
  return os;
}

int main(void) {
  Contact contact1("John", "Doe", "JD", "0123456789", "My dark secret");
  cout << contact1.m_firstName << endl;
  // cout << contact1 << endl;
  // string input;

  // while (true) {
  //   std::cout << "Enter command: ADD, SEARCH, EXIT" << std::endl;
  //   std::cin >> input;
  //   if (input == "ADD") {
  //   } else if (input == "SEARCH") {
  //   } else if (input == "EXIT") {
  //     break;
  //   }
  // }
  return (0);
}