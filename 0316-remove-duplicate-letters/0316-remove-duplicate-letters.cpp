class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastindx(26);
        vector<bool> taken(26, false);

        string result;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            lastindx[ch - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (taken[idx] == true)
                continue;

            while (result.length()>0 && result.back() > s[i] &&
                   lastindx[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[idx] = true;
        }
        return result;
    }
};