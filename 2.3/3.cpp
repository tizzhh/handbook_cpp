#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
// template <typename InIter1, typename InIter2, typename OutIter>
// OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2,
//                       InIter2 last2, OutIter out) {
//                         for (auto iter1 = first1; iter1 != last1; ++iter1) {
//                             bool check = false;
//                             for (auto iter2 = first2; iter2 != last2;
//                             ++iter2) {
//                                 if (*iter1 == *iter2) {
//                                     check = true;
//                                     break;
//                                 }
//                             }
//                             if (!check) {
//                                 *out++ = *iter1;
//                             }
//                         }
//                         return out;
//                       }

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2,
                      InIter2 last2, OutIter out) {
  auto iter1 = first1;
  auto iter2 = first2;
  while (iter1 != last1) {
    while (iter2 != last2 && *iter2 < *iter1) {
      ++iter2;
    }
    if (*iter1 < *iter2 || iter2 == last2) {
      *out++ = *iter1;
    } else if (iter2 != last2) {
      ++iter2;
    }
    ++iter1;
  }
  return out;
}

int main(void) {
  std::set<int> set1 = {2, 1, 3};
  std::set<int> set2 = {3, 2, 4};
  std::vector<int> result;

  SetDifference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                std::back_inserter(result));

  std::cout << "Set Difference: ";
  for (const int &num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}