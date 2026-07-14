class Solution {
    int n;
    vector<vector<long long>> memo; 

    long long solve(int i, int sign, vector<int>& nums) {
        if (i == n) return 0;

        int s = (sign == 1) ? 0 : 1;
        if (memo[i][s] != LLONG_MIN) return memo[i][s];

        long long take = (long long)sign * nums[i];
        long long extend = take + solve(i + 1, -sign, nums);

        return memo[i][s] = max(take, extend);
    }

public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        n = nums.size();
        memo.assign(n, vector<long long>(2, LLONG_MIN));

        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 1, nums)); 
        }
        return ans;
    }
};