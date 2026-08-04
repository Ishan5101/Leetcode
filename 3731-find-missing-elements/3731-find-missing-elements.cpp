class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        vector<bool> present(maxi - mini + 1, false);
        for (int x : nums) {
            present[x - mini] = true;
        }

        vector<int> ans;
        for (int i = 0; i < present.size(); i++) {
            if (!present[i]) {
                ans.push_back(mini + i);
            }
        }

        return ans;
    }
};