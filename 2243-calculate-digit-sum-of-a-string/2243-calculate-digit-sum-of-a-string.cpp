class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        while (n > k) {
            string newstr;
            for (int i = 0; i < n; i += k) {
                int sum = 0;
                for (int j = i; j < min(i + k, n); j++) {
                    sum += s[j] - '0';
                }
                newstr += to_string(sum);
            }
            s = newstr;
            n = s.length();
        }
        return s;
    }
};