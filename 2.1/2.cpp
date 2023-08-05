#include <deque>
#include <iostream>
#include <string>

int main(void) {
  int N, M, temp;
  std::cin >> N;
  std::deque<std::string> students;
  std::string student, pos;
  for (int i = 0; i != N; ++i) {
    std::cin >> student >> pos;
    if (pos == "top") {
      students.push_front(student);
    } else if (pos == "bottom") {
      students.push_back(student);
    }
  }

  std::cin >> M;
  for (int i = 0; i != M; ++i) {
    std::cin >> temp;
    std::cout << students[temp - 1] << '\n';
  }
}