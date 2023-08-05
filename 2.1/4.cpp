#include <iostream>
#include <list>
#include <string>

int main(void) {
  std::list<std::string> file;
  std::string temp, buff;
  while (true) {
    getline(std::cin, temp);
    if (temp.empty())
      break;
    file.push_back(temp);
  }

  auto iter = file.begin();

  while (std::cin >> temp) {
    if (temp == "Down" && iter != file.end()) {
      ++iter;
    } else if (temp == "Up" && iter != file.begin()) {
      --iter;
    } else if (temp == "Ctrl+X") {
      if (iter != file.end()) {
        buff = *iter;
        iter = file.erase(iter);
      }
    } else if (temp == "Ctrl+V") {
      if (!buff.empty())
        file.insert(iter, buff);
    }
  }

  for (const auto &str : file) {
    std::cout << str << '\n';
  }
}