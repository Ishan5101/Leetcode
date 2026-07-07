class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> v;

        while (n > 0) {
            int d = n % 10;
            if (d != 0)
                v.push_back(d);
            n /= 10;
        }

        reverse(v.begin(), v.end());

        long long x = 0;
        long long sum = 0;

        for (int d : v) {
            sum += d;
            x = x * 10 + d;
        }

        return x * sum;
    }
};