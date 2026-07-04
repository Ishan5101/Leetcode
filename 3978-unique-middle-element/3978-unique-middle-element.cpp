class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto v: nums){
            mp[v]++;
        }

        int mid=n/2;
        if(mp[nums[mid]]>1) return false;

        return true;
    }
};