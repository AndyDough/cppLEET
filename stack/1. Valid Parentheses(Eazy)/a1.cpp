#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

bool isValid(std::string s) {
  std::vector<char> openB{'d'};
  std::unordered_map<char, char> openToClose{
      {'{', '}'}, {'(', ')'}, {'[', ']'}};

  if (s.empty() || s.size() < 2) {
    return false;
  }

  for (const auto &e : s) {
    if (e == '(' || e == '{' || e == '[') {
      openB.push_back(e);
    } else if (openB.back() == 'd') {
      return false;
    } else {
      if (openToClose[openB.back()] != e) {
        return false;
      }
      openB.pop_back();
    }
  }

  return openB.back() == 'd';
}

int main() {

  if (isValid("()[]")) {
    std::cout << "Test Case Pass!\n";
  } else {
    std::cout << "You failed\n";
  }

  return 0;
}
