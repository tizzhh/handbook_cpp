#include <iostream>
#include <string>
#include <string_view>

bool NextToken(std::string_view &sv, const char &delim,
               std::string_view &token) {
  if (sv.empty()) {
    return false;
  }
  size_t pos = sv.find(delim);
  if (pos == std::string::npos) {
    pos = sv.size();
  }
  token = sv.substr(0, pos);
  // std::cout << "sv before removal:" << sv << '\n';
  if (pos == sv.size()) {
    sv.remove_prefix(pos);
  } else {
    sv.remove_prefix(pos + 1);
  }
  // std::cout << "sv after removal:" << sv << '\n';
  return true;
}

int main() {
  std::string_view sv = "Hello world and good bye";

  const char delimiter = ' ';
  std::string_view token;

  // Делим строку на токены по разделителю и перебираем эти токены:
  while (NextToken(sv, delimiter, token)) {
    // обрабатываем очередной token
    // например, печатаем его на экране:
    std::cout << token << "\n";
  }
  // for (int i = 0; i < 5; ++i) {
  //     NextToken(sv, delimiter, token);
  //     std::cout << token << "\n";
  // }
}