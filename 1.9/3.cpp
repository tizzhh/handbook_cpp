#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> Split(const std::string& str, char delimiter);

int main(void) {
    std::string str;
    char delim;
    std::cin >> str >> delim;

    std::vector<std::string> strtok = Split(str, delim);

    for (auto &str : strtok) {
        std::cout << str << '\n';
    }
}

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    if (str.empty()) return result;

    std::string temp = str;
    while(!temp.empty()) {
        size_t pos = temp.find(delimiter);
        if (pos == std::string::npos) {
            pos = temp.size();
        }
        result.push_back(temp.substr(0, pos));
        pos == temp.size() ? temp = temp.substr(pos, temp.size()) : temp = temp.substr(++pos, temp.size());
    }
    if (str.back() == delimiter)
        result.push_back("");
    return result;
}

// std::vector<std::string> Split(const std::string& str, char delimiter) {
//     std::vector<std::string> result;
//     size_t i = 0;
//     for (size_t j = 0; j != str.size(); ++j) {
//         if (str[j] == delimiter) {
//             result.push_back(str.substr(i, j - i));
//             i = j + 1;
//         }
//     }
//     result.push_back(str.substr(i));
//     return result;
// }