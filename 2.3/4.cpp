#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(void) {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a;
  std::vector<int> b;
  int temp;
  for (int i = 0; i < n; ++i) {
    std::cin >> temp;
    a.push_back(temp);
  }
  for (int i = 0; i < k; ++i) {
    std::cin >> temp;
    b.push_back(temp);
    auto low = std::lower_bound(a.begin(), a.end(), b[i]);
    if (low == a.begin() ||
        std::abs(*low - b[i]) < std::abs(*std::prev(low) - b[i])) {
      std::cout << *low << '\n';
    } else {
      std::cout << *std::prev(low) << '\n';
    }
  }
}