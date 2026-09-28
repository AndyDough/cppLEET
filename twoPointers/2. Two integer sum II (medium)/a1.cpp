// Two pointers solution
//
// Reqirement O(1) space
// tells me its gonna use two pointers
#include <ranges>
#include <vector>

std::vector<int> twoSum(std::vector<int> &numbers, int target) {

  // Early check for empty array
  if (numbers.empty()) {
    return {};
  }

  for (int p2{0}; p2 < static_cast<int>(numbers.size()); ++p2) {
    for (int p1{0}; p1 < static_cast<int>(numbers.size()); ++p1) {
      if (p1 == p2) {
        continue;
      }
      if (numbers[p1] + numbers[p2] == target) {
        ++p1;
        ++p2;
        return {p2, p1};
      }
    }
  }

  // loop iterate p2 backwards through the array
  // while (p2 < 0) {
  //   int difference{target - numbers[p1]};
  //
  //   // If the array doesn't have negative numbers
  //   if (difference <= 0) {
  //     --p2;
  //     continue;
  //   }
  //
  //   while (p1 < p2) {
  //     if (difference == numbers[p2]) {
  //       ++p1, ++p2;
  //       return {p1, p2};
  //     }
  //     ++p1;
  //   }
  //   --p2;
  // }
  //
  return {};
}
