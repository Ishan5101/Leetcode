class Solution {
public:
  
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> adj;
if (source == target)
    return 0;
        for (int bus = 0; bus < routes.size(); bus++) {
            for (int i : routes[bus]) {
                adj[i].push_back(bus);
            }
        }
        queue<int> q;
        vector<int> visited(1000,false);

            for (auto route:adj[source]){
                q.push(route);
                visited[route]=true;
            }
            int count=1;
            while(!q.empty()){
                int size=q.size();
                while(size--){
                    int route=q.front();
                    q.pop();

                    for(auto stop: routes[route]){
                        if(stop==target) return count;

                        for(auto nextstop: adj[stop]){
                            if(visited[nextstop]==false){
                                visited[nextstop]=true;
                                q.push(nextstop);
                            }
                        }
                    }
                }
                count++;
            }
            return -1;
    }
};