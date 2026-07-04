class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int> ans;

        if(m>n) return ans;

vector<int> ishan(26, 0);
vector<int> ish(26, 0);

for(char c: p ) ishan[c-'a']++;
for (int i = 0; i < m; i++) ish[s[i] - 'a']++;

   if (ish == ishan) ans.push_back(0);
       for (int right = m; right < n; right++) {
        int left = right - m;
        
        ish[s[right] - 'a']++;   
        ish[s[left] - 'a']--;  
if (ish == ishan) {
            ans.push_back(left + 1); 
        }
       }
        return ans;
    }
};