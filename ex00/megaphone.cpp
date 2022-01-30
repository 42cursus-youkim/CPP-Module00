#include <iostream>
#include <string>

std::string toUpper(std::string str) {
  std::string res = str;

  for (unsigned i = 0; i < str.length(); i++) {
    res[i] = std::toupper(str[i]);
  }
  return res;
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; i++)
      std::cout << toUpper(argv[i]);
  }
  std::cout << std::endl;
  return (0);
}