#include "PhoneBook.hpp"
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "Util.hpp"

using std::cin;
using std::cout;

const size_t NUM_COLUMNS = 3;
const size_t MAX_COLUMN_LENGTH = 10;

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

void PhoneBook::printHeader() const {
  printCell("Index");
  for (size_t i = 0; i < NUM_COLUMNS - 1; i++)
    printCell(names[i]);
  printCellLast(names[NUM_COLUMNS - 1]);
}

void PhoneBook::printCell(const string& cell) const {
  cout << std::setw(MAX_COLUMN_LENGTH)
       << truncateColumn(MAX_COLUMN_LENGTH, cell) << "|";
}

void PhoneBook::printCellLast(const string& cell) const {
  cout << std::setw(MAX_COLUMN_LENGTH)
       << truncateColumn(MAX_COLUMN_LENGTH, cell) << "\n";
}

void PhoneBook::printRow(const size_t index, const Contact& contact) const {
  const string columns[] = {contact.m_firstName, contact.m_lastName,
                            contact.m_nickname};
  printCell(size_to_string(index));
  for (size_t i = 0; i < NUM_COLUMNS - 1; i++)
    printCell(columns[i]);
  printCellLast(columns[NUM_COLUMNS - 1]);
}

void PhoneBook::printContacts() const {
  printHeader();
  for (size_t i = 0; i < CONTACT_SIZE; i++) {
    const Contact& contact = m_contacts[i];
    if (contact.isValid())
      printRow(i, contact);
  }
}
