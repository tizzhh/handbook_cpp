#include <iostream>
#include <set>
#include <string>

int main(void) {
  std::set<char> set;
  std::string buff;
  std::cin >> buff;
  for (const char &ch : buff) {
    set.insert(ch);
  }
  while (std::cin >> buff) {
    for (auto iter = set.begin(); iter != set.end();) {
      if ((buff.find(*iter)) == std::string::npos) {
        iter = set.erase(iter);
      } else {
        ++iter;
      }
    }
  }

  for (const auto &elem : set) {
    std::cout << elem;
  }
  std::cout << '\n';
}

// #include <iostream>
// #include <map>
// #include <set>
// #include <string>

// int main() {
//     std::map<char, int> counter;
//     std::string word;
//     int wordsCount = 0;
//     while (std::cin >> word) {
//         ++wordsCount;
//         std::set<char> letters(word.begin(), word.end());
//         for (char c : letters) {
//             ++counter[c];
//         }
//     }
//     for (auto [c, freq] : counter) {
//         if (freq == wordsCount) {
//             std::cout << c;
//         }
//     }
//     std::cout << "\n";
// }