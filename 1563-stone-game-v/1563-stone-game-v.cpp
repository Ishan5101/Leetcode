class Solution {
public:
int dp[501][501];
    int solve(int l,int r, vector<int>& prefix){
        if(l>=r) return 0;
int score=0;
if(dp[l][r]!=-1) return dp[l][r];
for(int mid=l;mid<r;mid++){

       int leftsum  = prefix[mid] - (l-1 >= 0 ? prefix[l-1] : 0);
        int rightsum= prefix[r]- prefix[mid];

        if(leftsum< rightsum){
            score=max(score, leftsum+solve(l,mid,prefix));

        }else if( leftsum> rightsum){
            score=max(score,rightsum+solve(mid+1,r,prefix));
        }else{
              score = max({score, leftsum + solve(l, mid, prefix), rightsum + solve(mid+1, r, prefix)});
        }
}
        return dp[l][r] =score;
    }
    int stoneGameV(vector<int>& nums) {

        memset(dp,-1, sizeof(dp));
        int n= nums.size();
        vector<int> prefix(n,0);
        prefix[0]= nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+ nums[i];
        }

        return solve(0,n-1, prefix);
    }
};