class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;

        for (int x : nums) {
            mp.insert(x);
        }

        for (int i = 1; i <= 100; i++) {
            int multiple = k * i;

            if (!mp.count(multiple)) {
                return multiple;
            }
        }

        return 101;
    }
};