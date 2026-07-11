class Solution {
public:
   int bfs(unordered_map<int, vector<int>>& adj, int p, int n, vector<int>& visited) {
    queue<int> q;

    visited[p] = 1;
    q.push(p);

    int counter = 0;   
    int edges = 0;    

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        counter++;
        edges += adj[u].size();

        for (auto v : adj[u]) {
            if (visited[v] == -1) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    edges /= 2;

    return edges == counter * (counter - 1) / 2;
}
    
};