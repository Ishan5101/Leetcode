class Solution {
public:
    int n, m;
    long long bfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= 0)
            return 0;
        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum += bfs(grid, i + 1, j);
        sum += bfs(grid, i, j + 1);
        sum += bfs(grid, i - 1, j);
        sum += bfs(grid, i, j - 1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {

        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(grid, i, j);

                    if (sum % k == 0)
                        count++;
                }
            }
        }
        return count;
    }
};