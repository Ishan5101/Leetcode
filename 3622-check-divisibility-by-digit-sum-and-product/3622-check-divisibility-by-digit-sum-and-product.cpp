class Solution {
public:
    bool checkDivisibility(int n) {
        int prod=1;
        int sum=0;
        int m= n;
        while(n){
            sum+= n%10;
            prod*=n%10;
            n/=10;
        }
        int ans=sum+prod;
      if(m%ans==0) return true; 
        return false;
    }
};