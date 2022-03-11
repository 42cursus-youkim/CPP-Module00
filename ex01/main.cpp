#include "Contact.hpp"
// #include "PhoneBook.hpp"

int main(void) {
  Contact contact;
  Entry test = {"John", "Doe", "Johny", "0123456789", "I love my mom"};

  contact.addContact(test);
  contact.printContact();
}
