class Solution {
public:
int n;
int dp[2][101][101];
int solve(vector<int>& piles, int person , int indx, int M){
    if(indx>=n) return 0;
    int result= (person==1) ? -1 : INT_MAX;
if(dp[person][indx][M]!=-1) return dp[person][indx][M];
    int stones=0;
    for(int x=1;x<= min(2*M, n-indx);x++){
        stones+=piles[indx+x-1];
        if(person==1){
            result= max(result, stones+ solve(piles,0,indx+x, max(M,x)));

        }else{
            result= min(result, solve(piles,1,indx+x, max(M,x)));
        }
    }
    return dp[person][indx][M]=result;
}
    int stoneGameII(vector<int>& piles) {
        n=  piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles, 1, 0 ,1 );
    }
};