// Solution was implemented with the answer's algorithm
// Also checked with the answer code

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

int characterReplacement(std::string s, int k) {
  int result{};

  std::unordered_set<char> uniqueC(s.begin(), s.end());

  for (const auto &c : uniqueC) {
    int r{}, l{}, count{};
    while (r < s.size()) {
      if (s[r] == c) {
        ++count;
      }

      while ((r - l + 1) - count > k) {
        if (s[l] == c) {
          --count;
        }
        ++l;
      }

      result = std::max(result, r - l + 1);
      ++r;
    }
  }

  return result;
}

int main() {
  std::cout << characterReplacement("BAAA", 0) << '\n';
  return 0;
}
