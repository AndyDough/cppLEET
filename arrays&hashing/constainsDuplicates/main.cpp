// Given an integer array nums, Return true if any values appears
// more than once in the array, otherwise return false.
#include <iostream>
#include <unordered_set>
#include <vector>

bool hasDuplicate(std::vector<int> &nums) {
  std::unordered_set<int> temp;

  for (int num : nums) {
    if (temp.contains(num)) {
      return true;
    }
    temp.insert(num);
  }

  return false;
}

int main() {
  std::vector<int> list1 = {1, 2, 3, 4};
  std::vector<int> list2 = {2, 3, 2, 4};

  std::cout << std::boolalpha;
  std::cout << hasDuplicate(list1) << '\n';
  std::cout << hasDuplicate(list2) << '\n';

  return 0;
}
