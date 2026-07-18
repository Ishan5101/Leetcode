class Solution {
public:
    bool solve(vector<vector<int>>& adj, int curr, vector<int>& col,
               int currcol) {
        queue<int> q;
        q.push(curr);
        col[curr] = currcol;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto next : adj[u]) {
                if (col[next] == col[u]) {
                    return false;
                } else if (col[next] == -1) {
                    col[next] = 1 - col[u];
                    q.push(next);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> col(v, -1);

        for (int i = 0; i < v; i++) {
            if (col[i] == -1) {
                if (solve(adj, i, col, 1)==false) {
                    return false;
                }
            }
        }
        return true;
    }
};