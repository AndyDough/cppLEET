#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// The goal of encode is to take in an array of strings and combine them into
// one really long string that can be decoded back to the original array
//
// my approach: We can separate each word with a symbol and a number to signify
// how long is each word
//
// That will make it easier to seperate each word later on in the decode
// function
std::string encode(std::vector<std::string> &strs) {
  std::string answer{};

  // Iterate through the vector of strings
  for (const auto &str : strs) {
    answer.append(std::to_string(str.length()));
    answer.append("#");
    answer.append(str);
  }
  // std::cout << answer;
  return answer;
}

// given a string with Num followed by a # which will tell us how long the
// string is gonna be to append to the vector
//
// 1. When we reach a num, check if the next char is a # to know how long the
// word is gonna be
std::vector<std::string> decode(std::string s) {
  std::vector<std::string> answer{};
  std::string temp{};

  for (auto i{0uz}; i < s.size();) {
    auto start{s.find('#', i)};
    auto length{static_cast<std::size_t>(std::stoi(s.substr(i)))};
    answer.push_back(s.substr(start + 1, length));
    i = start + 1 + length;
  }

  // for (const auto &e : answer) {
  //   std::cout << e << '\n';
  // }

  return answer;
}

int main() {
  std::vector<std::string> testEncode{"Hello", "World"};
  std::string testDecode{encode(testEncode)};

  if (testDecode == "5#Hello5#World") {
    std::cout << "Encode Test Pass\n";
  }

  if (decode(testDecode) == testEncode) {
    std::cout << "Decode Test Pass\n";
  }

  return 0;
}
