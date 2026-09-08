class Solution {
public:
    int countCommas(int n) {
        int count=0;
        int m=n;
        while(n){
            n=n/10;
            count++;
        }
      if(count<=3) return 0;

      return (m-1000+1);
    }
};