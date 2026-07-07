class Solution {
public:
void dfs(vector<bool>& visited, int idx,vector<vector<int>>& stones,int n){
    visited[idx]=true;
for(int i=0;i<n;i++){
    int r= stones[idx][0];
    int c=stones[idx][1];

    if((visited[i]==false) && (stones[i][0]==r || stones[i][1]==c) ){
        dfs(visited,i,stones,n);
    }
}

}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> visited(n,false);
        int groups=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true) continue;

            dfs(visited,i,stones,n);
groups++;


        }
        return n-groups;
    }
};