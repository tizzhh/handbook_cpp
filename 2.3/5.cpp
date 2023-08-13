#include <iostream>

#include <algorithm>
#include <vector>

template <typename Iter> void PrintResults(Iter iter, Iter last) {
  for (auto it = iter; it != last; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}

template <typename T> void Process(const std::vector<T> &data) {
  std::vector<T> filtered;

  std::copy_if(data.begin(), data.end(), std::back_inserter(filtered),
               [](const T &x) { return x > 0; });

  PrintResults(filtered.begin(), filtered.end());
}

int main(void) {
  std::vector<int> a = {-1, 0, -2, 3, 4};
  Process(a);
}