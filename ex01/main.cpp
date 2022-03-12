#include <stdlib.h>
#include <iostream>
#include <limits>
#include "PhoneBook.hpp"
#include "Util.hpp"

using std::cin;
using std::cout;

int main(void) {
  PhoneBook book;
  string line;

  while (true) {
    cout << "Enter a command: ADD | SEARCH | QUIT\n";
    if (not getline(cin, line))
      return EXIT_SUCCESS;
    const command cmd = parseCommand(line);
    switch (cmd) {
      case ADD:
        book.addContactFromInput();
        break;
      case SEARCH:
        book.printContacts();
        cout << "Enter index to search: ";
        size_t index;
        try {
          index = getIndexInput();
          clearCin();
        } catch (std::out_of_range& e) {
          clearCin();
          cout << "Invalid index\n";
          break;
        } catch (std::runtime_error& e) {
          return EXIT_FAILURE;
        }
        try {
          book.getContactAt(index).print();
        } catch (std::out_of_range& e) {
          cout << "Index out of range\n";
        } catch (std::runtime_error& e) {
          cout << "No contact at this index\n";
        }
        break;
      case QUIT:
        return EXIT_SUCCESS;
      default:
        break;
    }
  }
}
