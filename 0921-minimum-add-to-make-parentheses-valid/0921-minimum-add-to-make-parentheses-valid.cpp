class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,end=0;
        for(char ch:s){
            if(ch=='('){
                open++;
            }else if(open==0) end++;

            else{
                open--;
            }
        }
        return open+end;
    }
};