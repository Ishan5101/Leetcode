class Solution {
public:
    int getint(int num){
         int sum=0;
        while(num>0){
           
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans=nums;
        auto lambda=[&](int num1,int num2){
            int getsum1= getint(num1);
            int getsum2= getint(num2);
            if(getsum1!=getsum2) return getsum1<getsum2;

            return num1<num2;
        };
        sort(begin(ans),end(ans),lambda);

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }


        int yashu=0;
        for(int i=0;i<n;i++){
            int expected= ans[i];
            int curr=nums[i];

            if(expected == curr) continue;

            int idx= mp[expected];
            nums[i]=expected;
            nums[idx]=curr;
            mp[expected]=i;
            mp[curr]=idx;
            yashu++;

        }

        return yashu;
    }
};