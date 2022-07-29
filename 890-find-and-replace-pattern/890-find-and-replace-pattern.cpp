class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // int c = words.size();
        vector<string> ans;
        for(auto word:words){
            unordered_map<char,char> mp;
            unordered_set<char> s;
            int i;
            for(i=0;i<word.size();i++){
                if(mp.find(word[i])==mp.end()){
                    if(s.count(pattern[i])==0){
                        mp[word[i]]=pattern[i];
                        s.insert(pattern[i]);
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(mp[word[i]]!=pattern[i]){
                        break;
                    }
                }
            }
            if(i==word.size()) ans.push_back(word);
       }
        return ans;
    }
};