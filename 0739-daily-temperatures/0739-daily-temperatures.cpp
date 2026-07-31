class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> result(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>= nums[st.top()]) st.pop();

            if(st.size()==0) result[i]=0;
            else {
                result[i]= st.top()-i;
            }


            st.push(i);
        }
        return result;
    }
};