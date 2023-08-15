#include <iostream>
#include <queue>
#include <string>

void clear(std::priority_queue<int> &q) {
  std::priority_queue<int> empty;
  std::swap(q, empty);
}

int main(void) {
  std::string command;
  std::priority_queue<int> q;
  int temp;
  while (std::cin >> command) {
    if (command == "ADD") {
      std::cin >> temp;
      q.push(temp);
    } else if (command == "EXTRACT") {
      if (q.empty()) {
        std::cout << "CANNOT" << '\n';
      } else {
        std::cout << q.top() << '\n';
        q.pop();
      }
    } else if (command == "CLEAR") {
      clear(q);
    }
  }
}