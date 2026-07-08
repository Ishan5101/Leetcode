class Solution {
public:
bool bfs(unordered_map<int,vector<int>>& adj,int i,vector<int>& col){
    queue<int> q;
    q.push(i);
    col[i]=1;
    while(!q.empty()){
        auto u=q.front();
        q.pop();

        for(auto v: adj[u]){
            if(col[v]==col[u]) return false;


            if(col[v]==-1) {
                q.push(v);
                col[v]=1-col[u];
            }
        }
    }
            return true;

}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto ch: dislikes){
            int u=ch[0];
            int v=ch[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> col(n+1,-1);

        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(bfs(adj,i,col)==false) return false;
            }
        }
        return true;

    }
};