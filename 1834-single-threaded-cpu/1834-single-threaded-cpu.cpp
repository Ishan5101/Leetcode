class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>> sorted;
vector<int> result;

        for(int i=0;i<n;i++){
            int curr=tasks[i][0];
            int add=tasks[i][1];

            sorted.push_back({curr,add,i});
        }

        sort(sorted.begin(),sorted.end());
long long currtime=0;
int idx=0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
while(idx<n || !pq.empty()){
if(pq.empty() && currtime<sorted[idx][0]){
    currtime=sorted[idx][0];
}

while(idx<n && sorted[idx][0] <= currtime){
    pq.push({sorted[idx][1],sorted[idx][2]});
idx++;
}
pair<int,int> currtask=pq.top();
pq.pop();
currtime+=currtask.first;
result.push_back(currtask.second);
}
return result;
    }
};