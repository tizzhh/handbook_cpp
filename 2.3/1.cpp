#include <iostream>
#include <vector>

template <typename T> void Duplicate(std::vector<T> &v) {
  const size_t size = v.size();
  for (size_t i = 0; i != size; ++i) {
    v.push_back(v[i]);
  }
}

int main(void) {
  std::vector<int> a = {1, 2, 3};
  Duplicate(a);
}

// #include <algorithm>
// #include <vector>

// template <typename T>
// void Duplicate(std::vector<T>& v) {
//     v.reserve(v.size() * 2);
//     std::copy(v.begin(), v.end(), std::back_inserter(v));
// }