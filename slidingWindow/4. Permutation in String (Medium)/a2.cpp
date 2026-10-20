#include <iostream>
#include <string>
#include <unordered_map>

// intialize one hashmap to hold the char of s1 as the key
// and the value is the frequency that char appears in the string
bool checkInclusion(std::string s1, std::string s2) {
  std::unordered_map<char, int> count1;

  // Loop s1's char as key and value being frequence of the char
  for (const auto &e : s1) {
    count1[e]++;
  } // count1{'a': 1, 'b': 1, 'c': 1};

  int need{static_cast<int>(count1.size())};

  for (auto i{0}; i < s2.size(); ++i) {
    std::unordered_map<char, int> count2;
    int cur{0};
    int j{i};
    while (j < s2.size()) {
      ++count2[s2[j]];
      if (count2[s2[j]] > count1[s2[j]]) {
        break;
      } else if (count2[s2[j]] == count1[s2[j]]) {
        ++cur;
      }
      if (cur == need) {
        return true;
      }
      ++j;
    }
  }

  return false;
}

int main() {
  if (checkInclusion("abc", "lecabee")) {
    std::cout << "test pass\n";
  };

  return 0;
}
