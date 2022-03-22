#include "Util.hpp"
#include <iostream>
#include <limits>
#include <sstream>

string stringTransform(const string& str, charFunc func) {
  string res = str;

  for (unsigned i = 0; i < str.length(); i++) {
    res[i] = func(str[i]);
  }
  return res;
}

string trim(const string& str) {
  const string whitespace = " \t\n\r\f\v";
  string res = str;

  res.erase(0, res.find_first_not_of(whitespace));
  res.erase(res.find_last_not_of(whitespace) + 1);
  return res;
}

string truncateColumn(const size_t size, const string& column) {
  if (column.length() > size)
    return column.substr(0, size - 1) + ".";
  else
    return column;
}

string size_to_string(const size_t size)
{
  std::ostringstream stream;
  stream << size;
  return stream.str();
}

command parseCommand(const string& str) {
  const string parsed = stringTransform(trim(str), std::toupper);

  if (parsed == "ADD")
    return ADD;
  else if (parsed == "SEARCH")
    return SEARCH;
  else if (parsed == "EXIT")
    return EXIT;
  else
    return INVALID;
}

void clearCin() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

size_t getIndexInput() {
  size_t index;
  std::cin >> index;

  if (std::cin.eof())
    throw std::runtime_error("EOF");
  else if (std::cin.fail()) {
    throw std::out_of_range("Invalid index");
  }
  return index;
}