#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string toUpper(string str) {
  string res = str;

  for (unsigned i = 0; i < str.length(); i++) {
    res[i] = std::toupper(str[i]);
  }
  return res;
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; i++)
      cout << toUpper(argv[i]);
  }
  cout << endl;
  return (0);
}