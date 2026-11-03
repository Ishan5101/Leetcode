class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> p(n);
        p[0]=arr[0];

        for(int i=1;i<n;i++){
            p[i]=p[i-1]^arr[i];
        }

        vector<int> answer;
        for(auto q: queries){
            int left=q[0];
            int right=q[1];

            if(left==0) answer.push_back(p[right]);
            else answer.push_back(p[left-1]^p[right]);
        }
        return answer;
    }
};