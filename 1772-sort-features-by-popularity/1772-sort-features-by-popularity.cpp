class Solution {
public:

    struct cmp {
        bool operator()(pair<int,int> &a, pair<int,int> &b) {
            if(a.first == b.first)
                return a.second > b.second;   

            return a.first < b.first;     
        }
    };

    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {

        unordered_map<string,int> mp;

      
        for(auto &feature : features)
            mp[feature] = 0;

        for(auto &response : responses){

            unordered_set<string> st;

            stringstream ss(response);
            string word;

            while(ss >> word)
                st.insert(word);

            for(auto &word : st){
                if(mp.count(word))
                    mp[word]++;
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(int i = 0; i < features.size(); i++){
            pq.push({mp[features[i]], i});
        }

        vector<string> ans;

        while(!pq.empty()){
            ans.push_back(features[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};