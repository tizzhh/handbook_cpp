#include <iostream>
#include <unordered_set>

int main(void) {
  std::unordered_set<int> set;
  int buff;
  while (std::cin >> buff) {
    // auto [iter, inserted] = set.insert(buff);
    // if (inserted) {
    //     std::cout << "NO" << '\n';
    // } else {
    //     std::cout << "YES" << '\n';
    // }

    // if (set.contains(buff)) {
    //     std::cout << "YES" << '\n';
    // } else {
    //     std::cout << "NO" << '\n';
    // }

    if (set.insert(buff).second) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}