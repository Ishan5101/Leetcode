class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> bfs(unordered_map<int, vector<pair<int, int>>>& adj, int n,
                    int u) {
        vector<int> ans(n, 0);

        queue<int> q;
        ans[u] = 1;
        q.push(u);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr]) {
                int child = it.first;
                int w = it.second;

                ans[child] = (1LL * ans[curr] * w) % MOD;
                q.push(child);
            }
        }

        return ans;
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : conversions) {
            int a = vec[0];
            int b = vec[1];
            int w = vec[2];

            adj[a].push_back({b, w});
        }

        return bfs(adj, n, 0);
    }
};