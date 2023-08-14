#include <iostream>
#include <queue>
#include <set>

int main(void) {
  int n, k;
  std::cin >> n >> k;
  int temp;
  std::multiset<int> window;
  std::queue<int> numbers;
  for (int i = 1; i <= n; ++i) {
    std::cin >> temp;
    window.insert(temp);
    numbers.push(temp);
    if (i >= k) {
      std::cout << *window.begin() << '\n';
      auto iter = window.find(numbers.front());
      window.erase(iter);
      numbers.pop();
    }
  }
}