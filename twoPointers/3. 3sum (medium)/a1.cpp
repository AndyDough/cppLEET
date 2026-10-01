#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {

  std::vector<std::vector<int>> answer{};

  // sort nums from least to greatest
  std::sort(nums.begin(), nums.end());

  for (auto i{0}; i < std::size(nums); ++i) {
    // quick check whether or not any other possible 3sum exist
    if (nums[i] > 0) {
      break;
    }
    // skipping over duplicate starting values
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int left{i + 1};
    int right{static_cast<int>(nums.size() - 1)};
    while (left < right) {
      int sum{nums[left] + nums[right] + nums[i]};
      if (sum < 0) {
        ++left;
      } else if (sum > 0) {
        --right;
      } else {
        answer.push_back({nums[i], nums[left], nums[right]});
        ++left;
        --right;

        while (left < right && nums[left] == nums[left - 1]) {
          ++left;
        }
      }
    }
  }

  return answer;
}
