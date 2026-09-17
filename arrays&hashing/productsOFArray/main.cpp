#include <iostream>
#include <vector>

// Bruteforce solution
// Goal Get the product of every index except itself
//
// 1. Loop through the array, starting at the beginning index
//    - iterate through the rest of the numbers and get the product
//    - Skip the index of the current number
// 2. Append the product to the output array
// 3. continue until no numbers are left in nums
std::vector<int> productExceptSelf(const std::vector<int> &nums) {
  std::vector<int> output(nums.size());

  for (auto currentNum{0uz}; currentNum < nums.size(); ++currentNum) {
    // Loop through the array
    int product{1};
    for (auto i{0uz}; i < nums.size(); ++i) {
      if (i == currentNum) { // skips the current indexed number
        continue;
      }
      product *= nums[i];
    }
    output[currentNum] = product;
  }
  return output;
}

int main() {
  const std::vector<int> nums{1, 2, 3, 4};
  const std::vector<int> answer{24, 12, 8, 6};

  if (productExceptSelf(nums) == answer) {
    std::cout << "Test 1 Pass\n";
  } else {
    std::cout << "Test Failed\n";
  }

  return 0;
}
