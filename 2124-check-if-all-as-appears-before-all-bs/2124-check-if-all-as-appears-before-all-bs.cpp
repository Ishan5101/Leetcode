class Solution {
public:
    bool checkString(string s) {
        int n = s.size(); 
        int i=0;
        while(i<n){
            if(s[i]=='b' && s[i+1]=='a') return false;
            i++;
        }
        return true;
    }
};