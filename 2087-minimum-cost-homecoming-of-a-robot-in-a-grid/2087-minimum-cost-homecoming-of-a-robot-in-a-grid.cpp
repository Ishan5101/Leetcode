class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& ansrow, vector<int>& colans) {
        int r1= startPos[0];
        int c1= startPos[1];

        int r2=homePos[0];
        int c2=homePos[1];
int result=0;
        if(r2>=r1){
            for(int i=r1+1;i<r2+1;i++){
                result+=ansrow[i];
            }
        }else {
            for(int i=r1-1;i>=r2;i--){
                result+=ansrow[i];
            }
        }

        if(c2>=c1){
            for(int i=c1+1;i<c2+1;i++){
                result+=colans[i];
            }
        }else {
            for(int i=c1-1;i>=c2;i--){
                result+=colans[i];
            }
        }
return result;
    }
};