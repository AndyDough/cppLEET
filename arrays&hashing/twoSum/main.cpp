#include <iostream>
#include <unordered_map>
#include <vector>

// Classic two sum, return two numbers that add up to the target.
//
// If I remember correctly, to solve this problem iterate through the
// array of nums and check if the current number - target = a past number
// already seen
std::vector<int> twoSum(const std::vector<int> &nums, int target) {
  // intialized with the first value as the key and the value is the index
  std::unordered_map<int, int> seen{};

  // We want to know the index so can't use for range
  // Fail test case {-1, -2, -3, -4, -5} and -8 returns {0,4}
  for (auto i{0zu}; i < nums.size(); ++i) {
    if (seen.contains(target - nums[i])) {
      return std::vector<int>{static_cast<int>(seen[target - nums[i]]),
                              static_cast<int>(i)};
    }
    // Insert the checked value into the hashmap
    seen[nums[i]] = static_cast<int>(i);
  }

  // should never reach this realistically
  return std::vector{0, 0};
}

int main() {
  std::vector nums{3, 4, 5, 6};
  int target = 7;
  std::vector answer{0, 1};

  if (twoSum(nums, target) == answer) {
    std::cout << "Test case correct\n";
  }

  nums = {-1, -2, -3, -4, -5};
  target = -8;
  std::vector answer2{2, 4}; // why does it go to {0,4}???

  if (twoSum(nums, target) == answer2) {
    std::cout << "Test case 2 correct\n";
  }

  return 0;
}


// Neetcode solution if c++version < 20
//class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int, int> prevMap;
//
//         for (int i = 0; i < n; i++) {
//             int diff = target - nums[i];
//             if (prevMap.find(diff) != prevMap.end()) {
//                 return {prevMap[diff], i};
//             }
//             prevMap.insert({nums[i], i});
//         }
//         return {};
//     }
// };
