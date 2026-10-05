class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        if(n==2) return s+m;

        return s+m+(n/2-1)*(m-1);
    }
};