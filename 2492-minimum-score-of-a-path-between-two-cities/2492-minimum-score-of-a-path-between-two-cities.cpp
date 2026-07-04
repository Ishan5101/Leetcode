class Solution {
public:

    void dfs(int u,
             unordered_map<int, vector<pair<int,int>>>& adj,
             vector<bool>& visited,
             int& result) {

        visited[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int d = edge.second;

            result = min(result, d);

            if (!visited[v]) {
                dfs(v, adj, visited, result);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n + 1, false);  

        int result = INT_MAX;

        dfs(1, adj, visited, result);

        return result;
    }
};