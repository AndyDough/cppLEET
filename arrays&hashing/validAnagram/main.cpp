// Given two strings s and t, return true if the two strings are anagrams of
// each other, otherwise return false.

// An anagram is a string that contains the exact same characters as another
// string, but the order of the characters can be different.

#include <algorithm>
#include <iostream>
#include <string>

// The brute force method that jumps out to me is if both words contain the same
// amount certain letter I can determine if they are an anagram or not.
// So what we can do is sort both strings and return the comparison of both
// sorted string.
bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length()) {
    return false;
  }
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  return s == t;
}

int main() {
  std::string s1 = "anagram", t1 = "nagaram";
  std::cout << "s1: " << s1 << ", t1: " << t1
            << " -> isAnagram: " << (isAnagram(s1, t1) ? "true" : "false")
            << std::endl;

  std::string s2 = "rat", t2 = "car";
  std::cout << "s2: " << s2 << ", t2: " << t2
            << " -> isAnagram: " << (isAnagram(s2, t2) ? "true" : "false")
            << std::endl;

  return 0;
}
