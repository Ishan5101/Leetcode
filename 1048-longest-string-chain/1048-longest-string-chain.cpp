class Solution {
public:
    bool predec(string &prev, string &curr) {
        int m = prev.length();
        int n = curr.length();

        if (n - m != 1)
            return false;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (prev[i] == curr[j])
                i++;
            j++;
        }

        return i == m;
    }

    int lis(int n, vector<string>& words, int prev, int curr,
            vector<vector<int>>& dp) {

        if (curr == n)
            return 0;

        if (prev != -1 && dp[prev][curr] != -1)
            return dp[prev][curr];

        int taken = 0;

        if (prev == -1 || predec(words[prev], words[curr])) {
            taken = 1 + lis(n, words, curr, curr + 1, dp);
        }

        int skip = lis(n, words, prev, curr + 1, dp);

        if (prev != -1)
            dp[prev][curr] = max(taken, skip);

        return max(taken, skip);
    }

    static bool ishan(string &a, string &b) {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), ishan);

        int n = words.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return lis(n, words, -1, 0, dp);
    }
};