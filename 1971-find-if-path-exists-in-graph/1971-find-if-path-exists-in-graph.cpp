class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int s, int d) {
        if (s == d)
            return true;

        vis[s] = 1;

        for (auto it : adj[s]) {
            if (!vis[it]) {
                if (dfs(adj, vis, it, d))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        return dfs(adj, vis, source, destination);
    }
};