#include <iostream>
#include <string>
#include <unordered_map>

std::string minWindow(std::string s, std::string t) {
  std::string answer{};

  std::unordered_map<char, int> count;
  for (const auto &e : t) {
    ++count[e];
  }

  int need{static_cast<int>(count.size())};

  for (auto i{0uz}; i < s.size(); ++i) {
    std::unordered_map<char, int> count2;
    int cur{};
    std::size_t j{i};
    if (!count.contains(s[i])) {
      continue;
    }

    while (j < s.size()) {
      answer.push_back(s[j]);
      if (count.contains(s[j]) && (count[s[j]] < count2[s[j]])) {
        ++count2[s[j]];
        ++cur;
      }
      if (cur == need) {
        return answer;
      }
      ++j;
    }
  }

  return "";
}

int main() {
  if (minWindow("OUZODYXAZV", "XYZ") == "YXAZ") {
    std::cout << "Test Pass!\n";
  }
  return 0;
}
