class Solution {
public:
    int n, m;

    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    long long bfs(vector<vector<int>>& grid, int i, int j) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (vector<int>& dir : directions) {
                int i_ = r + dir[0];
                int j_ = c + dir[1];

                if (i_ >= 0 && i_ < n &&
                    j_ >= 0 && j_ < m &&
                    grid[i_][j_] > 0) {

                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    q.push({i_, j_});
                }
            }
        }

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