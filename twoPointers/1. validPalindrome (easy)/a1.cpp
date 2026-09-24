#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

// Given a string that could contain spaces, capital letters, and puctuation
// deterine if the string is a palindrome.
//
// Easy checks for edge cases:
//   1. If string is empty return false
//   2. If the string is one char return true
//
// brute force solution: loop backwards through the string and insert each
// character into an array ignoring all cases, spaces, and puctuation
//
// loop forward (ignoring cases, spaces, and puctuation) comparing the orginal
// string with the array that contains the reversed string.
//   - If char doesn't match up return false
//   - If loops reaches end without returning early return true
bool isPalindrome(std::string s) {
  std::vector<char> reverse{};
  std::vector<char> forward{};

  for (const auto &c : std::views::reverse(s)) {
    if (!std::isalnum(c)) { // Skips past all characters that are not a-z
      continue;
    }
    reverse.push_back(std::tolower(c));
  }
  for (const auto &c : s) {
    if (!std::isalnum(c)) { // Skips past all characters that are not a-z
      continue;
    }
    forward.push_back(std::tolower(c));
  }

  for (auto i{0uz}; i < reverse.size() - 1; ++i) {
    if (reverse[i] != forward[i]) {
      return false;
    }
  }

  return true;
}
