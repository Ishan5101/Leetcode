class Solution {
public:
    long long numberOfWays(string s) {

        int n = s.size();

        static long long dp[100001][3][4];
        memset(dp, 0, sizeof(dp));

        // Base case
        for (int i = 0; i <= n; i++)
            for (int last = 0; last < 3; last++)
                dp[i][last][3] = 1;

        for (int idx = n - 1; idx >= 0; idx--) {

            int curr = s[idx] - '0';

            for (int count = 2; count >= 0; count--) {

                for (int last = -1; last <= 1; last++) {

                    long long skip = dp[idx + 1][last + 1][count];

                    long long take = 0;

                    if (last == -1 || last != curr)
                        take = dp[idx + 1][curr + 1][count + 1];

                    dp[idx][last + 1][count] = skip + take;
                }
            }
        }

        return dp[0][0][0];
    }
};