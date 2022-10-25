class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="",s2="";
        for(auto w:word1){
            for(auto c:w){
                s1.push_back(c);
            }
        }
        for(auto w:word2){
            for(auto c:w){
                s2.push_back(c);
            }
        }
        return s1==s2;
    }
};