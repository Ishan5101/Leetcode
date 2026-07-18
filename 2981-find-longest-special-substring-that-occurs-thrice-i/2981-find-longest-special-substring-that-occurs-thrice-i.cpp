class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string curr="";
            for(int j=i;j<n;j++){
            if(curr.empty() || curr.back() == s[j]){
                    curr+=s[j];
                    mp[curr]++;
                }else break;
            }
        }
        int result=0;
        for(auto it: mp){
            string ishan=it.first;
            int count=it.second;
            if(count>=3 && ishan.length()>result){
                result=ishan.length();
            }
        }

        return result==0?-1 : result;
    }
};