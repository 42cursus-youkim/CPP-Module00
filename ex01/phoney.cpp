#include "Phoney.hpp"



int main(void) {
  PhoneBook phoneBook;

  phoneBook.addContact();
  phoneBook.printContacts();
  // Contact example("John", "Doe", "Johnny", "555-555-5555", "I am the best");
  // cout << example << endl;
  // phoneBook.addContact();
  // cout << phoneBook << endl;

  // string input;
  // while (true) {
  //   cout << "Enter command: ADD, SEARCH, EXIT" << endl;
  //   std::getline(cin, input);
  //   if (input == "ADD") {
  //     phoneBook.addContact();
  //     cout << phoneBook << endl;
  //   } else if (input == "SEARCH") {
  //   } else if (input == "EXIT") {
  //     break;
  //   }
  // }
  return (0);
}