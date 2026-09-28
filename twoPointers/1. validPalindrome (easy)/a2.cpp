// Two pointers method
//
// I'm assuming you loop forward through the given string skipping characters
// that aren't a-z.
//
// At the same time you are iterating a pointer backwards through the string
// doing the same thing as the first pointer, skipping characters that aren't
// a-z
//
// Once both pointers are pointing at a valid character, compare them to see if
// they equal eachother. If not return false.

#include <string>

bool isAZ(char c) {
  int lower{std::tolower(static_cast<unsigned int>(c))};
  if (lower >= 97 && lower <= 122) {
    return true;
  }
  return false;
}

bool isPalindrome(std::string s) {
  if (s.empty()) {
    return true;
  }

  std::size_t left{0};
  std::size_t right{s.size() - 1};

  // s="0P" fails
  while (left < right) {
    if (!std::isalpha(s[left]) || !std::isalnum(s[left])) {
      ++left;
    } else if (!std::isalpha(s[right]) || !std::isalnum(s[left])) {
      --right;
    } else {
      if (std::tolower(s[left]) != std::tolower(s[right])) {
        return false;
      }
      ++left;
      --right;
    }
  }

  return true;
}
