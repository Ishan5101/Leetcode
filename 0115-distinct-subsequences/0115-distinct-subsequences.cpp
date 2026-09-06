class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        int i=n;
        int j=m;
        vector<vector<int>> dp(n,vector<int>(m,-1));
         if(j<0) return 1;
        if(i<0) return 0;
         for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[i][j];
    }
};