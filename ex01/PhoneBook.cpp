#include "entry.hpp"
// #include "PhoneBook.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(void) {
  Entry entry = {"John", "Doe", "Johnny", "555-555-5555", "I am the best"};
  cout << entry.firstName << endl;
  cout << entry.lastName << endl;
  cout << entry.nickname << endl;
  cout << entry.phoneNumber << endl;
  cout << entry.darkestSecret << endl;
}
