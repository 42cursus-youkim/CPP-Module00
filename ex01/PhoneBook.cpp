#include "PhoneBook.hpp"
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "Util.hpp"

using std::cin;
using std::cout;

void PhoneBook::addContact(Contact entry) {
  const size_t index = m_counter.getValue();

  m_contacts[index] = entry;
  m_counter.increment();
}

// NOTE: will terminate program if ctrl-d is pressed
static void getNonEmptyLine(const string& prompt, string& line) {
  while (line.empty()) {
    cout << prompt << ": ";
    if (not getline(std::cin, line))
      exit(EXIT_FAILURE);
  }
}

void PhoneBook::addContactFromInput() {
  Contact entry;
  getNonEmptyLine("First Name", entry.m_firstName);
  getNonEmptyLine("Last Name", entry.m_lastName);
  getNonEmptyLine("Nickname", entry.m_nickname);
  getNonEmptyLine("Phone Number", entry.m_phoneNumber);
  getNonEmptyLine("Darkest Secret", entry.m_darkestSecret);

  addContact(entry);
}

Contact& PhoneBook::getContactAt(const size_t index) {
  if (not m_counter.indexInRange(index))
    throw std::out_of_range("Index out of range");

  Contact& contact = m_contacts[index];
  if (not contact.isValid())
    throw std::runtime_error("No contact at this index");

  return contact;
}

void PhoneBook::printHeader() {
  cout << std::setw(MAX_COLUMN_LENGTH) << "Index"
       << "|";
  for (size_t i = 0; i < NUM_COLUMNS - 1; i++)
    cout << std::setw(MAX_COLUMN_LENGTH)
         << truncateColumn(MAX_COLUMN_LENGTH, names[i]) << "|";
  cout << std::setw(MAX_COLUMN_LENGTH)
       << truncateColumn(MAX_COLUMN_LENGTH, names[NUM_COLUMNS - 1]) << "\n";
}

void PhoneBook::printRow(const size_t index,
                         const size_t size,
                         const string columns[]) const {
  cout << std::setw(MAX_COLUMN_LENGTH) << index << "|";
  for (size_t i = 0; i < size - 1; i++)
    cout << std::setw(MAX_COLUMN_LENGTH)
         << truncateColumn(MAX_COLUMN_LENGTH, columns[i]) << "|";
  cout << std::setw(MAX_COLUMN_LENGTH)
       << truncateColumn(MAX_COLUMN_LENGTH, columns[size - 1]) << "\n";
}

void PhoneBook::printContacts() const {
  PhoneBook::printHeader();
  for (size_t i = 0; i < CONTACT_SIZE; i++) {
    const Contact& contact = m_contacts[i];
    const string arr[] = {contact.m_firstName, contact.m_lastName,
                          contact.m_nickname};
    if (contact.isValid())
      printRow(i, NUM_COLUMNS, arr);
  }
}
