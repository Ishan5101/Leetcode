class Solution {
public:
int n;
int m;
int non=0;int result=0;
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void backtrack(vector<vector<int>>& grid,int curr,int i , int j){
    if(i<0 || j< 0 || i>=n ||j>=m || grid[i][j]==-1) return ;

    if(grid[i][j]==2){
        if(curr==non){
            result++;
        }
        return;
    }
      int temp = grid[i][j];
    grid[i][j] = -1;
       for(vector<int> dir:directions) {
            int nexti = i + dir[0];
            int nextj = j + dir[1];
            backtrack(grid, curr+1,nexti , nextj);
        }
        grid[i][j] =temp;
}


    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m= grid[0].size();


int startx=0;
int starty=0;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==0) non++;

        if(grid[i][j]==1) 
    {
        startx=i;
        starty=j;

    }
    }
}
non+=1;
int curr=0;
backtrack(grid,curr,startx,starty);

return result;
    }
};