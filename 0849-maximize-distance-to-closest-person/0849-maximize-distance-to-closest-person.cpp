class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                int mn = INT_MAX;

            for (int j = 0; j < n; j++) {
                    if (seats[j] == 1) {
                        mn = min(mn, abs(i - j));
                    }
                }

                ans = max(ans, mn);
            }
        }

        return ans;
    }
};