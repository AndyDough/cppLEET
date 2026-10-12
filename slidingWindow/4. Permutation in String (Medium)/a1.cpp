#include <iostream>
#include <string>
#include <vector>

bool checkInclusion(std::string s1, std::string s2) {
  std::vector<int> countS1(26);
  std::vector<int> countS2(26);

  // create the two frequency arrays
  for (auto i{0}; i < s1.size(); ++i) {
    ++countS1[s1[i] - 'a'];
    ++countS2[s2[i] - 'a'];
  }

  int matches{};
  for (auto i{0}; i < 26; ++i) {
    if (countS1[i] == countS2[i]) {
      ++matches;
    }
  }

  return false;
}

int main() {
  if (checkInclusion("abc", "lecabee")) {
    std::cout << "Test pass";
  }

  return 0;
}
