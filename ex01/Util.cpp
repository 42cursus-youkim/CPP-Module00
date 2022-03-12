#include "Util.hpp"
#include <iostream>
#include <limits>

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

command parseCommand(const string& str) {
  const string parsed = stringTransform(trim(str), std::toupper);

  if (parsed == "ADD")
    return ADD;
  else if (parsed == "SEARCH")
    return SEARCH;
  else if (parsed == "QUIT")
    return QUIT;
  else
    return INVALID;
}

void clearBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
