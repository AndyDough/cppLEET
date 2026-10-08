#include <iostream>
#include <string>
#include <unordered_set>

// s = "pwwkew" output was 2
int lengthOfLongestSubstring(std::string s) {
  int l{}, longestS{};

  // record seen characters
  std::unordered_set<char> seen{};

  for (int r{}; r < s.size(); ++r) {
    while (seen.contains(s[r])) {
      seen.erase(s[l]);
      ++l;
    }
    seen.insert(s[r]);
    longestS = std::max(longestS, r - l + 1);
  }

  return longestS;
}

int main() {
  std::cout << lengthOfLongestSubstring("pwwkew") << '\n';

  return 0;
}
