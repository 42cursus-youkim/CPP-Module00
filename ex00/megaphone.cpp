#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

typedef int (*charFunc)(int);

string stringTransform(const string& str, charFunc func) {
  string res = str;

  for (unsigned i = 0; i < str.length(); i++) {
    res[i] = func(str[i]);
  }
  return res;
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; i++)
      cout << stringTransform(argv[i], std::toupper);
  }
  cout << "\n";
  return (0);
}