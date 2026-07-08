class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int n=rooks.size();
  vector<int> xs(n), ys(n);  
          for(int i=0;i<n;i++){
            xs[i]=rooks[i][0];
            ys[i]=rooks[i][1];
        }
        int moves=0;
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());
        for(int j=0;j<n;j++){
            moves+=abs(xs[j]-j)+abs(ys[j]-j);
        }
        return moves;
    }
};