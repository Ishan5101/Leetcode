class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != '*') {
                st.push(c);
            } else {
                if (!st.empty())
                    st.pop();
            }
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};