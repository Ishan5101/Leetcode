class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixgcd(n);
        int mxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mxi = max(mxi, nums[i]);
            prefixgcd[i] = __gcd(nums[i], mxi);
        }

        sort(prefixgcd.begin(), prefixgcd.end());

        vector<int> ans;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            ans.push_back(__gcd(prefixgcd[i], prefixgcd[j]));
           //  prefixgcd[j]);
             i++;
             j--;
        }

        long long sum = 0;
        for (auto i : ans) {
            sum += i;
        }

        return sum;
    }
    };