#include <iostream>
#include <string>
#include <vector>

// find if s1's permutations exist in s2
//
bool checkInclusion(std::string s1, std::string s2) {

  // if s1 larger, it cannot have a permutation in s2
  if (s1.length() > s2.length()) {
    return false;
  }

  std::vector<int> countS1(26);
  std::vector<int> countS2(26);

  // create the two frequency arrays counts
  // the amount of times a lower case letter shows up
  // in both strings
  for (auto i{0}; i < s1.size(); ++i) {
    ++countS1[s1[i] - 'a'];
    ++countS2[s2[i] - 'a'];
  }

  // counts how many matches the frequency array have
  int matches{};
  for (auto i{0}; i < 26; ++i) {
    if (countS1[i] == countS2[i]) {
      ++matches;
    }
  }

  int l{0};
  for (int r{static_cast<int>(s1.size())}; r < s2.size(); ++r) {

    if (matches == 26) {
      return true;
    }

    // current s2 character
    int index{s2[r] - 'a'};
    ++countS2[index];
    if (countS1[index] == countS2[index]) {
      ++matches;
    } else if (countS1[index] + 1 == countS2[index]) {
      --matches;
    }

    index = (s2[l] - 'a');
    --countS2[index];
    if (countS1[index] == countS2[index]) {
      ++matches;
    } else if (countS1[index] - 1 == countS2[index]) {
      --matches;
    }

    // Sliding window from left to right
    ++l;
  }

  return matches == 26;
}

int main() {
  if (checkInclusion("abc", "lecabee")) {
    std::cout << "Test pass";
  }

  return 0;
}
