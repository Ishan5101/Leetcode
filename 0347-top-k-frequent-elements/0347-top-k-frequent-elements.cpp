class Solution {
public:
struct cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        vector<int> result;
        for(auto ishan: mp){
            pq.push(ishan);
        }
        for(int i=1;i<=k;i++){
           auto curr = pq.top();
pq.pop();
            result.push_back(curr.first);
        }
        return result;
    }
};