#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

// s = "au" output was 2
int lengthOfLongestSubstring(std::string s) {
  int l{}, r{}, longestS{};

  // record seen characters
  std::unordered_set<char> seen{};

  while (r < s.size() - 1) {
    if (seen.contains(s[r])) {
      seen.erase(s[l]);
      ++l;
    }
    seen.insert(s[r]);
    longestS = std::max(longestS, r - l + 1);
    ++r;
  }

  return longestS;
}

int main() {
  std::cout << lengthOfLongestSubstring("pwwkew") << '\n';

  return 0;
}
