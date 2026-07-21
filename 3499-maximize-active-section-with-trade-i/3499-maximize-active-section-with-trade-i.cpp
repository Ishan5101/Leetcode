class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> ishan;
        int n = s.size();
        int countof1 = 0;

        for(auto it: s){
            if(it == '1') countof1++;
        }

        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;

                while(i < n && s[i] == '0'){
                    i++;
                }
                ishan.push_back(i - start);
            } else {
                i++; 
            }
        }

        int maxi = 0;

        for(int i = 1; i < ishan.size(); i++){
            maxi = max(maxi, ishan[i] + ishan[i-1]);
        }

        return countof1 + maxi;
    }
};