#include <vector>

int search(std::vector<int> &nums, int target) {
  int answer{}; // Start at the center

  if (nums.size() < 2) {
    if (nums[0] == target) {
      return 0;
    } else {
      return -1;
    }
  }

  // Binary search: Always check the middle of the half
  int upperBound{static_cast<int>(nums.size()) - 1};
  int lowerBount{0};

  // [2, 5] target = 0
  while (lowerBount <= upperBound) {
    int center{(upperBound + lowerBount) / 2};
    if (target < nums[center]) {
      upperBound = center - 1;
    } else if (target > nums[center]) {
      lowerBount = center + 1;
    } else if (target == nums[center]) {
      return center;
    }
  }

  return -1;
}

int main() { return 0; }
