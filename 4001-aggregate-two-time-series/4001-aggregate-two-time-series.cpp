class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        vector<vector<int>> ans;

        int n = series1.size();
        int m = series2.size();

        int i = 0, j = 0;

        while (i < n || j < m) {

            int currentTime;

            if (j == m || (i < n && series1[i][0] < series2[j][0])) {
                currentTime = series1[i][0];
            }
            else if (i == n || series2[j][0] < series1[i][0]) {
                currentTime = series2[j][0];
            }
            else {
                currentTime = series1[i][0];
            }

            int value1 = (i < n) ? series1[i][1] : 0;
            int value2 = (j < m) ? series2[j][1] : 0;

            ans.push_back({currentTime, value1 + value2});

            if (i < n && series1[i][0] == currentTime)
                i++;

            if (j < m && series2[j][0] == currentTime)
                j++;
        }

        return ans;
    }
};