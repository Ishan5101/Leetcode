class Solution {
public:

    int solve (int i,int j, vector<int>& nums) {
        if(i>j) return 0;
        if(i==j) return nums[i];

        int taken1= nums[i]+ min(solve(i+2,j,nums),solve(i+1,j-1,nums));
         int taken2= nums[j]+ min(solve(i,j-2,nums),solve(i+1,j-1,nums));
return max(taken1,taken2);

    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();

        int total_score= 0;

        for(int i=0;i<n;i++){
            total_score+=nums[i];
        }

        int player1= solve(0,n-1,nums);
        int player2= total_score-player1;

        return player1>=player2;
    }
};