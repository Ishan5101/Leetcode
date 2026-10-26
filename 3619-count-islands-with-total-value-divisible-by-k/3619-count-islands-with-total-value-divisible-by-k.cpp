class Solution {
public:
    int n, m;
    // vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    long long dfs(vector<vector<int>>& grid, int i, int j, int k) {
  if (i < 0 || i >= n || j < 0 || j >= m ||
            grid[i][j] <= 0) {
            return 0;
        }               
        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs(grid, i + 1, j, k);
        sum += dfs(grid, i - 1, j, k);
        sum += dfs(grid, i, j - 1, k);
        sum += dfs(grid, i, j + 1, k);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {

                    long long sum = dfs(grid, i, j, k);
                    if (sum % k == 0)
                        count++;
                }
            }
        }
        return count;
    }
};