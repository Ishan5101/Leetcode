class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n,-1);
        int compID=0;
        component[0]=compID;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] > maxDiff){
                compID++;
            }
            component[i]=compID;
        }
        vector<bool> result;

        for(auto& query: queries){
            int u=query[0];
            int v=query[1];

            result.push_back(component[u]==component[v]);
        } 
        return result;
    }
};