class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(begin(s),end(s))) return 0;
        if(n==2) return -1;
        char mini = *min_element(begin(s), end(s));
        char maxi = *max_element(begin(s), end(s));

        if(s[0]==mini || s[n-1]==maxi) return 1;
            char maxmid = *max_element(begin(s)+1, end(s)-1);
        char minmid = *min_element(begin(s)+1, end(s)-1);
        
        if(s[0] > maxmid && s[n-1] < minmid) {
            return 3;
        }

        return 2;
    }
};