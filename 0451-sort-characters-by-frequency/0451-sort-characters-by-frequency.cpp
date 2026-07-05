class Solution {
public:
typedef pair<char,int> p;

struct lambda{
    bool operator()(p &p1, p &p2){
        return p1.second<p2.second;
    }
};
    string frequencySort(string s) {
       priority_queue<p,vector<p>, lambda> pq;
       unordered_map<char,int> mp;

       string result="";
       for(char ch:s){
        mp[ch]++;
       }  
       for(auto it: mp){
        pq.push({it.first,it.second});
       }
       while(!pq.empty()){
        p temp=pq.top();
        pq.pop();
        result+=string(temp.second,temp.first);
       }
       return result;
    }
};