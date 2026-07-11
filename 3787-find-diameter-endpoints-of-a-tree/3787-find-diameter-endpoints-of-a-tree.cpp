class Solution {
public:
    void dfs(int u, int parent, int d,
             vector<vector<int>>& adj,
             vector<int>& dist) {
        dist[u] = d;
        for (int v : adj[u]) {
            if (v != parent) {
                dfs(v, u, d + 1, adj, dist);
            }
        }
    }

    int farthestNode(vector<int>& dist) {
        int node = 0;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] > dist[node])
                node = i;
        }
        return node;
    }

    string findSpecialNodes(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist0(n);
        dfs(0, -1, 0, adj, dist0);
        int A = farthestNode(dist0);

       
        vector<int> distA(n);
        dfs(A, -1, 0, adj, distA);
        int B = farthestNode(distA);

        vector<int> distB(n);
        dfs(B, -1, 0, adj, distB);

        int diameter = distA[B];

        string ans;
        for (int i = 0; i < n; i++) {
            if (max(distA[i], distB[i]) == diameter)
                ans.push_back('1');
            else
                ans.push_back('0');
        }

        return ans;
    }
};