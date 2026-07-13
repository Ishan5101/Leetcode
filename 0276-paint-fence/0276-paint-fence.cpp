class Solution {
public:
typedef long long ll;
    int numWays(int n, int k) {
        ll same=k;
        ll diff=k*(k-1);
        if(n==1) return k;

        ll total=same+diff;

        for(int i=3;i<=n;i++){
             same=diff*1;
             diff=total*(k-1);

total=same+diff;
        }
    return (int) total;

    }
};