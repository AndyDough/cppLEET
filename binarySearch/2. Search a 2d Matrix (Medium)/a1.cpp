#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {

  int upper{static_cast<int>(matrix.size()) - 1};
  int lower{0};

  int upperCol{static_cast<int>(matrix[0].size()) - 1};
  int lowerCol{0};
  // Searching the rows (Outer loop)
  while (lower <= upper) {
    int centerRow{(upper + lower) / 2};

    if (target < matrix[centerRow][lowerCol]) {
      upper = centerRow - 1;
    } else if (target > matrix[centerRow][upperCol]) {
      lower = centerRow + 1;
    } else {

      while (lowerCol <= upperCol) {
        int centerCol{(upperCol + lowerCol) / 2};
        if (target < matrix[centerRow][centerCol]) {
          upperCol = centerCol - 1;
        } else if (target > matrix[centerRow][centerCol]) {
          lowerCol = centerCol + 1;
        } else if (target == matrix[centerRow][centerCol]) {
          return true;
        }
      }
    }
  }

  return false;
}
