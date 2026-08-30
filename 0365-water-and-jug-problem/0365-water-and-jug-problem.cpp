class Solution {
public:
int GCD(int a, int b){
    while(b != 0 ){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
    bool canMeasureWater(int x, int y, int z) {
        // return true;

        if(x+y< z) return false;
        if((z%GCD(x,y))==0) return true;

return false;

    }
};