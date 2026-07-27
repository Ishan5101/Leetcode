class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi= nums[n-1]-1;
        int maxitwo=nums[n-2]-1;


        return maxi*maxitwo;

    }
};