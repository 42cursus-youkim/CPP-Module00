#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) {
  PhoneBook book;
  Contact test = {"John", "Doe", "Johny", "0123456789", "I love my mom"};

  book.addContact(test);
  book.printContact();
}
