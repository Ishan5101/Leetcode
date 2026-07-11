class Solution {
public:
    vector<int> toposort(unordered_map<int, vector<int>>& adj,
                         vector<int>& indegree, int n) {
        vector<int> result;
        queue<int> q;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                counter++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto v: adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                      result.push_back(v);
                counter++;
                q.push(v);
                }
            }
        }

        if(counter==n) return  result;

        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return toposort(adj, indegree, numCourses);
    }
};