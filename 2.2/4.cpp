#include <iostream>
#include <map>
#include <set>
#include <string>

int main(void) {
  int n, page;
  std::string word;
  std::cin >> n;
  std::map<int, std::set<std::string>> dict;
  for (int i = 0; i < n; ++i) {
    std::cin >> word >> page;
    dict[page].insert(word);
  }

  for (const auto &[page, set] : dict) {
    std::cout << page;
    for (const auto &word : set) {
      std::cout << ' ' << word;
    }
    std::cout << '\n';
  }
}