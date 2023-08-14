#include <iostream>
#include <stack>

int main(void) {
  std::stack<char> s;
  char temp;
  bool no = false;

  while (!no && std::cin >> temp) {
    if (temp == '(' || temp == '[' || temp == '{') {
      s.push(temp);
    } else if (temp == ')') {
      if (s.empty() || s.top() != '(') {
        no = true;
      }
      s.pop();
    } else if (temp == ']') {
      if (s.empty() || s.top() != '[') {
        no = true;
      }
      s.pop();
    } else if (temp == '}') {
      if (s.empty() || s.top() != '{') {
        no = true;
      }
      s.pop();
    }
  }

  if (!no && s.empty()) {
    std::cout << "YES" << '\n';
  } else {
    std::cout << "NO" << '\n';
  }

  return 0;
}

// #include <iostream>
// #include <stack>
// #include <string>

// bool IsCorrect(const std::string& sequence) {
//     std::stack<char> brackets;

//     for (char bracket : sequence) {
//         if (bracket == '(' || bracket == '{' || bracket == '[') {
//             brackets.push(bracket);
//         } else {
//             if (brackets.empty()) {
//                 return false;
//             }
//             char top = brackets.top();
//             if ((top == '(' && bracket == ')') || (top == '{' && bracket ==
//             '}') || (top == '[' && bracket == ']')) {
//                 brackets.pop();
//             } else {
//                 return false;
//             }
//         }
//     }

//     return brackets.empty();
// }

// int main() {
//     std::string sequence;
//     std::getline(std::cin, sequence);
//     if (IsCorrect(sequence)) {
//         std::cout << "YES\n";
//     } else {
//         std::cout << "NO\n";
//     }
// }