class Solution {
public:
int MOD = 1e9 + 7;
vector<vector<vector<int>>> dp;

int solve(int n,vector<int>& nums,int idx,int firt,int second){

if(idx==n){
    bool ishan=(firt!=0 && second!=0);
    bool ishan1=(firt==second);

    return (ishan && ishan1)?1:0;

}
if (dp[idx][firt][second] != -1)
    return dp[idx][firt][second];
int skip=solve(n,nums,idx+1,firt,second);
int take1=solve(n,nums,idx+1,__gcd(firt,nums[idx]),second);
int take2=solve(n,nums,idx+1,firt,__gcd(second,nums[idx]));


return dp[idx][firt][second]=((long long)skip+take1+take2)%MOD;


}
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
dp.assign(n + 1, vector<vector<int>>(201, vector<int>(201, -1)));
        return solve(n,nums,0,0,0);
    }
};