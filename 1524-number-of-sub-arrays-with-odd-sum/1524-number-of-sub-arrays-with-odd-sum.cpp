class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int M=1e9+7;
        int n=arr.size();
        int sum=0;
        int even=1;
        int count=0;
        int odd=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];

            if(sum%2==0){
                //even+odd=odd
                count=(count+odd)%M;
                even++;
            }else{
                count=(count+even)%M;
                odd++;
            }
        }
        return count;
    }
};