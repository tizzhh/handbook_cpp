#include <iostream>
#include <list>
#include <string>

int main(void) {
  std::list<std::string> file;
  std::string temp;
  while (true) {
    getline(std::cin, temp);
    if (temp.empty())
      break;
    file.push_back(temp);
  }

  auto iter = file.begin();

  bool shift = false;
  auto shift_iter = file.begin();
  int shift_offset = 0;
  std::list<std::string> buff;
  while (std::cin >> temp) {
    if (temp == "Down" && iter != file.end()) {
      ++iter;
      if (!shift) {
        shift_iter = iter;
      } else {
        ++shift_offset;
      }
    } else if (temp == "Up" && iter != file.begin()) {
      --iter;
      if (!shift) {
        shift_iter = iter;
      } else {
        --shift_offset;
      }
    } else if (temp == "Ctrl+X") {
      if (shift_iter == iter && iter == file.end())
        continue;

      buff.clear();
      if (shift_iter == iter) {
        auto temp_iter = iter;
        iter = std::next(iter);
        buff.splice(buff.begin(), file, temp_iter);
      } else if (shift_offset < 0) {
        buff.splice(buff.begin(), file, iter, shift_iter);
        iter = shift_iter;
      } else {
        buff.splice(buff.begin(), file, shift_iter, iter);
      }
      shift = false;
      shift_iter = iter;
      shift_offset = 0;
    } else if (temp == "Ctrl+V") {
      if (buff.empty())
        continue;
      if (shift_offset < 0) {
        iter = file.erase(iter, shift_iter);
      } else if (shift_offset > 0) {
        iter = file.erase(shift_iter, iter);
      }
      file.insert(iter, buff.begin(), buff.end());
      shift = false;
      shift_iter = iter;
      shift_offset = 0;
    } else if (temp == "Shift") {
      shift = true;
      shift_iter = iter;
    }
  }

  for (const auto &str : file) {
    std::cout << str << '\n';
  }
}