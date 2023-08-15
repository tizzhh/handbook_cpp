#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

int main(void) {
  std::string word;
  std::unordered_map<std::string, int> freqs;
  size_t k;
  std::cin >> k;
  while (std::cin >> word) {
    ++freqs[word];
  }

  std::vector<std::pair<std::string, int>> sorted(freqs.begin(), freqs.end());
  // std::sort(sorted.begin(), sorted.end(), [](const auto &p1, const auto &p2)
  // {
  //     return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
  // });
  std::partial_sort(sorted.begin(), sorted.begin() + std::min(sorted.size(), k),
                    sorted.end(), [](const auto &p1, const auto &p2) {
                      return std::tie(p2.second, p1.first) <
                             std::tie(p1.second, p2.first);
                    });

  for (size_t i = 0; i < k && i < sorted.size(); ++i) {
    std::cout << sorted[i].first << '\t' << sorted[i].second << '\n';
  }
}
