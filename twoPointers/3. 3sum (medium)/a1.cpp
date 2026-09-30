#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> answer{};

  // sort nums from least to greatest
  std::sort(nums.begin(), nums.end());

  for (auto i{0}; i < std::size(nums) - 1; ++i) {
    int diff{-nums[i]};
    int left{0};
    int right{static_cast<int>(nums.size() - 1)};
    while (left < right) {
      int sum{nums[left] + nums[right]};
      if (sum < diff) {
        ++left;
      } else if (sum > diff) {
        --right;
      } else if (sum == diff) {
        answer.push_back({nums[i], nums[left], nums[right]});
        break;
      }
    }
  }

  return answer;
}
