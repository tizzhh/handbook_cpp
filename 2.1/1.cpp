#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename T> void Print(const T &data, const std::string &delim) {
  int size = data.size(), i = 0;
  for (const auto &elem : data) {
    i == size - 1 ? std::cout << elem : std::cout << elem << delim;
    ++i;
  }
  std::cout << '\n';
}

int main() {
  std::vector<int> data = {1, 2, 3};
  Print(data, ", "); // 1, 2, 3
}