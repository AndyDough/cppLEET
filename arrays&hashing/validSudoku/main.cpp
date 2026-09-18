#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// One pass solution recording each number into 3 different
// data structures
// 1. hashmap for rows
// 2. hashmap for cols
// 3. array of hashsets for 3x3 squares

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  std::unordered_map<int, std::unordered_set<char>> rowMap{};
  std::unordered_map<int, std::unordered_set<char>> colMap{};
  std::array<std::unordered_set<char>, 9> squareMap{};

  std::size_t boardSize = board.size();
  for (auto r{0uz}; r < boardSize; ++r) {
    for (auto c{0uz}; c < boardSize; ++c) {
      char current = board[r][c];
      if (current == '.') {
        continue;
      }
      std::size_t squareIndex{(r / 3) * 3 + (c / 3)};

      if (rowMap[r].contains(current) || colMap[c].contains(current) ||
          squareMap[squareIndex].contains(current)) {
        return false;
      }

      rowMap[r].insert(current);
      colMap[c].insert(current);
      squareMap[squareIndex].insert(current);
    }
  }

  return true;
}
