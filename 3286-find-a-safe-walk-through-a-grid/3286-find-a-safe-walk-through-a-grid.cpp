class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        priority_queue<vector<int>> pq;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        pq.push({startHealth, 0, 0});
        best[0][0] = startHealth;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int rem = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == m - 1 && y == n - 1)
                return true;

            if (rem < best[x][y]) continue;

            for (auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newHealth = rem - grid[nx][ny];

                if (newHealth > 0 && newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    pq.push({newHealth, nx, ny});
                }
            }
        }

        return false;
    }
};