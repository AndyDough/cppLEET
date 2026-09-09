#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool hasDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> seen{};

    if (nums.empty()) {
      return true;
    }

    for (const auto &e : nums) {
      if (seen.contains(e)) {
        return true;
      }
      seen.insert(e);
    }
    return false;
  }
};

int main() {
  Solution sol{};
  std::vector nums{1, 2, 3, 3};
  std::vector nums2{1, 2, 3, 4};

  if (sol.hasDuplicate(nums)) {
    std::cout << "test complete";
  }

  if (!sol.hasDuplicate(nums2)) {
    std::cout << "test complete";
  }

  return 0;
}
