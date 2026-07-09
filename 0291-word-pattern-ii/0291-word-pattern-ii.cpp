class Solution {
public:
  bool solve(string& pattern, string& s, int pi, int si, 
           unordered_map<char,string>& c2s, 
           unordered_map<string,char>& s2c){
    
    if(pi == pattern.size() && si == s.size()) return true;
    if(pi == pattern.size() || si == s.size()) return false;
    
    char c = pattern[pi];
    
    if(c2s.count(c)){
        string mapped = c2s[c];
        if(s.substr(si, mapped.size()) != mapped) return false;
        return solve(pattern, s, pi+1, si+mapped.size(), c2s, s2c);
    }
    
  
    for(int len = 1; len <= s.size() - si; len++){
        string sub = s.substr(si, len);
        if(s2c.count(sub)) continue;  
        
        c2s[c] = sub;
        s2c[sub] = c;
        
        if(solve(pattern, s, pi+1, si+len, c2s, s2c)) return true;
        
        c2s.erase(c);
        s2c.erase(sub);
    }
    return false;
}

bool wordPatternMatch(string pattern, string s) {
    unordered_map<char,string> c2s;
    unordered_map<string,char> s2c;
    return solve(pattern, s, 0, 0, c2s, s2c);
}
};