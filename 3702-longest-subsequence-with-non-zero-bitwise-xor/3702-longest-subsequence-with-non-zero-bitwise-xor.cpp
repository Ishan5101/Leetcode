class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n= nums.size();
        int finalxor=0;
        bool allzeros=true;

        for(auto x: nums){

            finalxor= (finalxor^x);

            if(x!=0) allzeros=false;
        }

if(allzeros) return 0;

if(finalxor==0 ) return n-1;
else return n;



return 0;
        }
};