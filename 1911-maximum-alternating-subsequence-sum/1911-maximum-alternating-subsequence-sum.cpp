class Solution {
public:
 long long solve(vector<int>& nums,int n,int idx,bool flag  ,vector<vector<long long>> & dp) {
if(idx>=n) return 0;
if(dp[idx][flag]!=-1) return dp[idx][flag];
        long long skip=solve(nums,n,idx+1,flag,dp);
        long long val=nums[idx];

        if(flag==false){
            val=-val;
        }

        long long take=val+solve(nums,n,idx+1,!flag,dp);

        return dp[idx][flag]=max(take,skip);
 
 }

    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

vector<vector<long long>> dp (n + 1, vector<long long>(2, -1));
        bool flag=true;
        return solve(nums,n,0,flag,dp);
    }
};