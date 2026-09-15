class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int, vector<int>> hash;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
        }

        for(auto p : hash) {

            vector<int> pos = p.second;            if(pos.size() == 3) {

             
                if(pos[1] - pos[0] == pos[2] - pos[1]) {
                    count++;
                }
            }
        }

        return count;
    }
};