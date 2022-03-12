#include <iostream>
#include "PhoneBook.hpp"

using std::cout;
using std::endl;

int main(void) {
  PhoneBook book;
  Contact test1 = {"Maribel", "Hearn", "Mary",
                   "0123456789 this is very long phone number",
                   "I love my mom"};
  Contact test2 = {"Usami", "Renko", "Renk", "871447832", "I love my dad"};

  for (int i = 0; i < 10; i++) {
    book.addContact(test1);
    book.addContact(test2);
  }
  Contact& contact = book.getContactAt(0);
  contact.printHeader();
  contact.printSimple();
  contact.printFull();
}
