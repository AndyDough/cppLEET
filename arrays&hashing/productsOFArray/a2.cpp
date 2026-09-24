// product of array other than self
//
// Prefix and Suffix optimal solution
//
// We are going to initialize two variables
// Prefix: to hold the product of all indexes before current
// Postfix: to hold the product of all indexes after current
//
// Loop through the array from left to right for prefix skipping
// current
//
// Loop through the array from right to left for postfix skipping current
//
// After multiply pre and post and insert into result array at current index

#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  std::vector<int> result(nums.size(), 1);

  // Looping forward for prefixes
  for (auto i{1uz}; i < nums.size(); i++) {
    result[i] = result[i - 1] * nums[i - 1];
  }

  int postFix{1};
  // looping backwards for postfix
  for (auto i{std::ssize(nums) - 1}; i >= 0; --i) {
    result[i] *= postFix;
    postFix *= nums[i];
  }

  return result;
}
