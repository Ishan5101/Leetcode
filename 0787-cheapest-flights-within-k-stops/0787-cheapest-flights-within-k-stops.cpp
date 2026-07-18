class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];

        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        dist[src] = 0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int stop=it.first;
            int node= it.second.first;
            int cost=it.second.second;

            if(stop>k) continue;
            for(auto &x: adj[node]){
                int next=x.first;
                int wt=x.second;

                if(cost+wt < dist[next]){
                    dist[next]=cost+wt;
                    q.push({stop+1,{next,dist[next]}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1 : dist[dst];
    }
};