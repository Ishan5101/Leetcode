class Solution {
public:
    bool predec( string &prev,string & curr){
        int m=prev.length();
        int n=curr.length();

        if(m>=n || n-m!=1) return false;
          int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;

    }
    int lis(int n,vector<string>words,int prev,int curr,vector<vector<string>>& dp){
        if(curr==n) return 0;
if(prev!=-1 && dp[prev][curr]!=-1) return dp[prev][curr];
        int taken=0;
        if(prev!=-1 || predec(words[prev],words[curr])){
            taken= 1+ lis(n,words,curr,curr+1);
        }

        int skip=lis(n,words,prev,curr+1);


        if(prev != -1)
            t[prev][curr] =  max(taken, skip);
        
        return max(taken, skip);
    }
       static bool ishan(string &s1,string& s2){
            return s1.length()<s2.length();
        }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
vector<vector<string>> dp(n+1,vector<string> (n+1,-1));
        sort(begin(words),end(words),ishan);

        return lis(n,words,-1,0,dp);

    }
};