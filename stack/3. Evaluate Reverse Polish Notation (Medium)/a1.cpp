#include <cctype>
#include <print>
#include <string>
#include <vector>

int evalRPN(std::vector<std::string> &tokens) {
  std::vector<int> stack;

  for (const auto &e : tokens) {
    if (std::isdigit(e.back())) {
      stack.push_back(std::stoi(e));
    } else {
      int num2{stack.back()};
      stack.pop_back();
      int num1{stack.back()};
      stack.pop_back();

      switch (e[0]) {
      case '+':
        stack.push_back(num1 + num2);
        break;
      case '-':
        stack.push_back(num1 - num2);
        break;
      case '/':
        stack.push_back(num1 / num2);
        break;
      case '*':
        stack.push_back(num1 * num2);
        break;
      }
    }
    std::print("Current stack:\n");
    for (const auto &e : stack) {
      std::print("{}\n", e);
    }
  }

  return stack.back();
}

int main() {
  std::vector<std::string> tokens{"1", "2", "+", "3", "*", "4", "-"};

  std::print("Result: {}", evalRPN(tokens));
}
