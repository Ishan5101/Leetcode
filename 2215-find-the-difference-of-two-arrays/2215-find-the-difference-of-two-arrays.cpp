class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> final;
        vector<int> ans1, ans2;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {

            bool found = false;

            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                bool duplicate = false;
                for (int k = 0; k < ans1.size(); k++) {
                    if (ans1[k] == nums1[i]) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate)
                    ans1.push_back(nums1[i]);
            }
        }

  
        for (int i = 0; i < m; i++) {

            bool found = false;

            for (int j = 0; j < n; j++) {
                if (nums2[i] == nums1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                bool duplicate = false;
                for (int k = 0; k < ans2.size(); k++) {
                    if (ans2[k] == nums2[i]) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate)
                    ans2.push_back(nums2[i]);
            }
        }

        final.push_back(ans1);
        final.push_back(ans2);

        return final;
    }
};