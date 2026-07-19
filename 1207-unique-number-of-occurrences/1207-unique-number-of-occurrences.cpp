class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        vector<bool> visited(n+1,false);

        for(auto ch: arr){
            mp[ch]++;
        }

        for(auto it:mp){
            if(visited[it.second]) return false;


            visited[it.second]=true;
        }
return true;
    }
};