class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set <string> bankset(bank.begin(),bank.end());
        unordered_set<string> visited;

        queue<string> q;
        q.push(start);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto curr=q.front();
                q.pop();
                if(curr==end) return level;
                for(char c:"ACGT"){
                    for(int i=0;i<curr.length();i++){
string ishan=curr;
ishan[i]=c;
                if(visited.find(ishan) == visited.end() && bankset.find(ishan)!=bankset.end()){
                        visited.insert(ishan);
                        q.push(ishan);
                }
                    }
                }
                
            }
            level++;
        }
return -1;
    }
};