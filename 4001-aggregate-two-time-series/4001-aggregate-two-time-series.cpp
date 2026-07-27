class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n=series1.size();
        int m = series2.size();
        int i=0;
        int j=0;
        while(i<n || j<m){
            int currtime=0;
            if(j==m || (i<n && series1[i][0]< series2[j][0])){
                currtime=series1[i][0];
            }else if (i==n || (j<m && series1[i][0] > series2[j][0])){
                currtime=series2[j][0];
            }else {
                currtime=series1[i][0];
            }

            int value1= (i<n)?series1[i][1]: 0;
            int value2= (j<m )? series2[j][1]:0;
            ans.push_back({currtime,value1+value2});


            if (i<n && series1[i][0]==currtime)
                i++;

            if (j<m && series2[j][0]==currtime)
                j++;
        }
        return ans;
    }
};