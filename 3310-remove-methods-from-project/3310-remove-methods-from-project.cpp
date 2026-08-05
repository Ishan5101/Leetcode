class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        vector<int> indegree(n,0);

        for(auto &edge : invocations){
            int u= edge[0];
            int v= edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        q.push(k);
        visited[k]=true;

        while(!q.empty()){
            int curr= q.front();
            q.pop();
            for(auto & ishan: adj[curr]){
                indegree[ishan]--;
                if(!visited[ishan]){
                    q.push(ishan);
                    visited[ishan]= true;

                }
            }
        }
vector<int> result;
bool ishan1=false;
for(int i=0;i<n;i++){
    if(visited[i] && indegree[i]>0){
     ishan1= true;
     break;


    }
    if(!visited[i]){
        result.push_back(i);
    }

}
if(ishan1){
    vector<int> final;
    for(int i=0;i<n;i++){
        final.push_back(i);
    }
    return final;

} 
return result;
    }
};