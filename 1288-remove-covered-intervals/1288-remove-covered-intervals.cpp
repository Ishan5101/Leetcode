class Solution {
public:
// struct ishan{
// auto operator(vector<int> v1,vector<int> v2){

// }
//};
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> results;
        auto ishan = [] (vector<int>& vec1, vector<int>& vec2){
            if(vec1[0]==vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
        };
        sort(intervals.begin(),intervals.end(),ishan);
        results.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(results.back()[0]<= intervals[i][0] && results.back()[1]>= intervals[i][1]) continue;

            results.push_back(intervals[i]);
        }
        return results.size();
    }
};