#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int rowCount = grid.size();
        int colCount = grid.at(0).size();
        for (int i = 1; i < rowCount; ++i) {
           grid[i][0] = grid[i][0] + grid[i-1][0];
        }
        for (int i = 1; i < colCount; ++i) {
            grid[0][i] = grid[0][i] + grid[0][i-1];
        }

        for (int i = 1; i < rowCount; ++i) {
            for (int j = 1; j < colCount; ++j) {
                grid[i][j] = std::min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
            }
        }

        return grid[rowCount - 1][colCount - 1];
    }
};

//int main() {
//    std::vector<std::vector<int>> grid{
//            {1,3,1},
//            {1,5,1},
//            {4,2,1}
//    };
//    int a = Solution().minPathSum(grid);
//
//    std::cout << "Hello, World!"<< a << std::endl;
//    return 0;
//}