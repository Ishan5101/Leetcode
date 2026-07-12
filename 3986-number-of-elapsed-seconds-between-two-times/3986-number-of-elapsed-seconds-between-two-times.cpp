class Solution {
public:
    int tostring(string& t){
        int h = stoi(t.substr(0,2));
        int m=stoi(t.substr(3,2));
        int s=stoi(t.substr(6,2));
        int ans= 3600*h+60*m+s;

        return ans;

    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return tostring(endTime)-tostring(startTime);
    }
};