class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ishan(n);

        int maxi = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= maxi) {
                ishan[i] = true;
            } else {
                ishan[i] = false;
            }
        }

        return ishan;
    }
};