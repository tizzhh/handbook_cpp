#include <iostream>
#include <vector>
#include <string>

std::string CommonPrefix(const std::vector<std::string>& words);

int main(void) {
    std::vector<std::string> words = {"aboba", "abobaaboba", "aboba"};

    std::cout << CommonPrefix(words) << '\n';
}

std::string CommonPrefix(const std::vector<std::string>& words) {
    std::string result, short_str;
    if (!words.size()) return result;
    size_t shortest_str = words[0].size();
    short_str = words[0];
    for (const auto &str : words) {
        if (str.size() < shortest_str) {
            shortest_str = str.size();
            short_str = str;
        } 
    }
    for (size_t i = 0; i < shortest_str; ++i) {
        for (const auto &str : words) {
            if (str[i] != short_str[i]) return result;
        }
        result += short_str[i];
        
    }
    return result;
}