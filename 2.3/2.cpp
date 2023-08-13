#include <iostream>
#include <vector>

template <typename Iter> Iter Unique(Iter first, Iter last) {
  auto iter = first;
  auto last_iter = --last;
  for (; iter != last_iter;) {
    if (*iter == *std::next(iter)) {
      // *(last_iter) = *std::next(iter);
      for (auto temp = std::next(iter); temp != last_iter; ++temp) {
        *temp = *(std::next(temp));
      }

      std::cout << "after shift" << '\n';
      for (auto temp2 = first; temp2 != last; ++temp2) {
        std::cout << *temp2 << ' ';
      }
      std::cout << '\n';

      --last_iter;
      continue;
    }
    ++iter;
  }
  return ++last_iter;
}

// template <typename Iter>
// Iter Unique(Iter first, Iter last) {
//     auto it1 = first;
//     auto it2 = first;
//     while (it2 != last) {
//         if (it1 != it2) {
//             *it1 = *it2;
//         }
//         ++it1;
//         const auto& value = *it2;
//         while (it2 != last && *it2 == value) {
//             ++it2;
//         }
//     }
//     return it1;
// }

int main(void) {
  std::vector<int> a = {1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8};

  auto iter = Unique(a.begin(), a.end());
  a.erase(iter, a.end());

  for (const auto &elem : a) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}