class Solution {
public:
    string decodeString(string s) {
       stack<int> nums;
       stack<string> str;

       int curr=0;
       string curri="";
       for(char ch: s){
            if (isdigit(ch)) {
                curr = curr * 10 + (ch - '0');
            }else if( ch=='['){
                nums.push(curr);
                str.push(curri);
                curr=0;
                curri="";
            } else if (ch == ']') {
                int repeat = nums.top();
                nums.pop();

                string prev = str.top();
                str.pop();

                while (repeat--) {
                    prev += curri;
                }

                curri = prev;
            }

  else {
                curri += ch;
            }
        }

        return curri;
       
                
    }
};