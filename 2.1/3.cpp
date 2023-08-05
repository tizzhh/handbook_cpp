#include <deque>
#include <iostream>
#include <string>

void MakeTrain();

int main(void) { MakeTrain(); }

void MakeTrain() {
  std::deque<size_t> trains;

  char oper = 0;
  while (std::cin >> oper) {
    std::string dir;
    size_t car = 0;
    std::cin >> dir >> car;
    if (oper == '+') {
      if (dir.front() == 'l') {
        trains.push_front(car);
      } else {
        trains.push_back(car);
      }
    } else {
      if (car > trains.size()) {
        trains.erase(trains.begin(), trains.end());
      } else if (dir.front() == 'l') {
        trains.erase(trains.begin(), trains.begin() + car);
      } else {
        trains.resize(trains.size() - car);
      }
    }
  }
  for (auto train : trains) {
    std::cout << train << ' ';
  }
  std::cout << '\n';
}
