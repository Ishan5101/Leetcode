class Solution {
public:
  vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(string ishan: equations){
            if(ishan[1]=='=') Union(ishan[0]-'a', ishan[3]-'a');
        }
        for(string ishan : equations){
            if(ishan[1]=='!') {
                int first= find(ishan[0]-'a');
                int second= find(ishan[3]-'a');

                if( first==second ) return false;

                            }
        }
        return true;
    }
};