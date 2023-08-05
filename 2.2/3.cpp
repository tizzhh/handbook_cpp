#include <iostream>
#include <set>
#include <string>

int main(void) {
  std::set<std::string> sys;
  std::string buff;

  while (std::cin >> buff) {
    for (int i = buff.length() - 1; i >= 0; --i) {
      if (buff[i] == '/') {
        std::string substr = buff.substr(0, i + 1);
        sys.insert(substr);
      }
    }
  }
  for (const auto &elem : sys) {
    std::cout << elem << '\n';
  }
}