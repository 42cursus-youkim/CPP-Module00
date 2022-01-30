#include "Phoney.hpp"

int main(void) {
  PhoneBook phoneBook;

  phoneBook.addContact();
  cout << phoneBook[0] << endl;
  // Contact contact1("John", "Doe", "JD", "0123456789", "My dark secret");
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