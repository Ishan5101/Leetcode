class Solution {
public:
 bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int i=0;
        int counter=0,ans=0;
        for(int j=0;j<n;j++){
            if(isvowel(s[j])){
                counter++;
            }

            if(j-i+1>k){
                if(isvowel(s[i])){
                    counter--;

                }
                i++;
            }
              if (j - i + 1 == k)
                ans = max(ans, counter);
            
        }
        return ans;

    }
};