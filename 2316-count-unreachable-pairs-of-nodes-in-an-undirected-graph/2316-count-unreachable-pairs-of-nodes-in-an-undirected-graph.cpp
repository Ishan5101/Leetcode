class Solution {
public: 
    vector<int> parent;
    vector<int> rank;
    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it: edges){
            int first= it[0];
            int second= it[1];

            Union(first,second);
        }

        unordered_map<int , int> mp;
        for(int i=0;i<n;i++){
            int parentt= find(i);

            mp[parentt]++;
        }
        long long result=0;
        long long remain= n ;
        for(auto it: mp){
            long long size= it.second;
            result+= size*(remain-size);

            remain-=size;
        }
        return result;
    }
};