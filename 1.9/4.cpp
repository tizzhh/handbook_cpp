#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter);

int main(void) {
    std::vector<std::string> tokens = {"What"};
    std::cout << Join(tokens, '_') << '\n';
}

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result;
    if (tokens.empty()) return result;
    for (size_t i = 0, size = tokens.size(); i != size; ++i) {
        result += tokens[i];
        if (i != size - 1) result += delimiter;
    }
    return result;
}