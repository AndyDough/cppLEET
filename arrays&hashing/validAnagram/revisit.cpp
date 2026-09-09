#include <iostream>
#include <unordered_map>

// What I remeber is for a word to be an anagram it has to have the same
// letters that the other word could have as well as the same amount of letters
//
// To solve this we can try using a hashmap to index each letter with the
// amount of time each letter shows up.
//
// What we'll need:
// 2 hashmaps
bool isAnagram(std::string s, std::string t) {
  std::unordered_map<char, int> s1{};
  std::unordered_map<char, int> s2{};

  if (s.length() != t.length()) {
    return false;
  }

  for (const auto &e : s) {
    s1[e]++;
  }

  for (const auto &e : t) {
    s2[e]++;
  }

  return s1 == s2;
}

int main() {
  std::string s{"racecar"};
  std::string t{"carrace"};

  if (isAnagram(s, t)) {
    std::cout << "test one correct\n";
  }

  s = "jar";
  t = "jam";

  if (!isAnagram(s, t)) {
    std::cout << "test two correct\n";
  }

  return 0;
}
