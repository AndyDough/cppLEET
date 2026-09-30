// Two pointers solution
//
// Reqirement O(1) space
// tells me its gonna use two pointers
//
// Instead of having both pointers start that the front
// have them start at opposite ends
//
// loop
//   add both pointer values together
//
//   if sum is larger than target
//      iterate the right ptr
//   if sum is smaller than target
//      iterate the left ptr
//   if sum is equal to target
//      return {leftptr + 1, rightptr + 1}
#include <vector>

std::vector<int> twoSum(std::vector<int> &numbers, int target) {
  int left{0};
  int right{static_cast<int>(numbers.size()) - 1};

  if (numbers.empty()) {
    return {};
  }

  while (left < right) {
    int sum{numbers[left] + numbers[right]};

    if (sum < target) {
      ++left;
    } else if (sum > target) {
      --right;
    } else if (sum == target) {
      return {left + 1, right + 1};
    }
  }

  return {};
}
