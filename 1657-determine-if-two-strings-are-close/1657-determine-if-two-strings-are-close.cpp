class Solution {
public:
    bool closeStrings(string s, string s0) {
        vector<int> w1(26,0),w2(26,0);
        set<int> s1,s2;
        for(char ch: s){
            w1[ch-'a']++;
            s1.insert(ch);
        }
           for(char ch: s0){
            w2[ch-'a']++;
            s2.insert(ch);
        }
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
return w1==w2 && s1==s2;
    }
};