class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int counter=0;
        int maxi=*max_element(begin(nums),end(nums));
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            if(nums[i]!=maxi) {counter+=abs(nums[i]-maxi);}
        }
        return counter;
    }
};