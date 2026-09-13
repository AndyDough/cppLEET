#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using arrayOfStrs = std::vector<std::vector<std::string>>;

arrayOfStrs groupAnagrams(const std::vector<std::string> &strs) {
  arrayOfStrs answer{};
  // The hash map contains the group of sorted anagrams with the key being the
  // groups of already seen strings
  std::unordered_map<std::string, std::vector<std::string>> groups{};

  for (const auto &e : strs) {
    auto temp = e;
    std::sort(temp.begin(), temp.end());
    groups[temp].push_back(e);
  }

  for (const auto &e : groups) {
    answer.push_back(e.second);
  }

  return answer;
}

int main() { return 0; }
