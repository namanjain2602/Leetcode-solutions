class Solution {
private:
    pair<bool, int> dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return {false, 0};
        if (grid[i][j] == 0 || grid[i][j] == 2) return {true, 0};
        grid[i][j] = 2;
        auto [isTopValid, topMoves] = dfs(grid, i - 1, j);
        auto [isBottomValid, bottomMoves] = dfs(grid, i + 1, j);
        auto [isLeftValid, leftMoves] = dfs(grid, i, j - 1);
        auto [isRightValid, rightMoves]= dfs(grid, i, j + 1);
        if(isTopValid && isBottomValid && isLeftValid && isRightValid) {
            return {true, 1 + (leftMoves + rightMoves + topMoves + bottomMoves)};
        }

        return {false, 0};
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int moves = 0;
        for(int i = 0; i < grid.size(); i++) { // O(n)
            for(int j = 0; j < grid[i].size(); j++) { // O(m)
                if(grid[i][j] == 1) {
                    auto [isValid, numMoves] = dfs(grid, i, j);
                    if(isValid) moves += numMoves;
                }
            }
        }
        return moves;
    }
};