class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        if(x!=y){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> ans(n,0);
        for(int src=1;src<=n;src++){
             vector<int> dist(n + 1, -1);
             queue<int> q;
             dist[src]=0;
            q.push(src);

            while(!q.empty()){
 auto node=q.front();
            q.pop();

            for( auto nei: adj[node]){
                 if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        q.push(nei);
                    }

            }


            } for (int dest = 1; dest <= n; dest++) {
                if (src != dest) {
                    ans[dist[dest] - 1]++;
                }
            }
        

        }
        return ans;
    }
};