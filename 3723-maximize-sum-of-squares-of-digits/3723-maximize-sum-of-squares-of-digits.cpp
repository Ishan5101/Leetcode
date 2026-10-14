class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
           string ishan="";
        if(sum > 9*num) return ishan;   
        int maxi=9;
        string yashi;
        while(num>0){
            int oj= min(maxi,sum);
            yashi+=char('0'+oj);
            sum-=oj;
            num--;
        }
        if(sum==0) return yashi;

        return "";
    }
};