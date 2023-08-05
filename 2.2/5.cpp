#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

int main(void) {
  size_t n, m;
  std::cin >> m >> n;
  std::unordered_map<std::string, int> words;
  std::string word;
  for (size_t i = 0; i != m; ++i) {
    std::cin >> word;
    if (word.length() == n) {
      ++words[word];
    } else {
      for (size_t j = n; j <= word.length(); ++j) {
        ++words[word.substr(j - n, n)];
      }
    }
  }

  std::vector<std::pair<std::string, int>> sorted(words.begin(), words.end());

  std::sort(sorted.begin(), sorted.end(), [](const auto &p1, const auto &p2) {
    return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
  });

  for (const auto &elem : sorted) {
    std::cout << elem.first << " - " << elem.second << '\n';
  }
}