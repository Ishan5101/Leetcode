class ValidWordAbbr {
public:
unordered_map<string,string> mp;
    string getabbr(string word){
        int n=word.size();
        if(n<=2) return word;
        return word.front()+to_string(n-2)+word.back();
    }
    ValidWordAbbr(vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        for(auto& word:st){
            string abbr=getabbr(word);
            if(!mp.count(abbr)){
                mp[abbr]=word;

            }else if(mp[abbr]!=word){
                mp[abbr]="";
            }
        }
    }
    
    bool isUnique(string word) {
        string abbr= getabbr(word);
        if(!mp.count(abbr)) return true;


        return mp[abbr]==word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */