class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> hmap;
        map<string,char> hmap2;
        istringstream ss(s);
        string word; // for storing each word
        int i=0;
        int size = pattern.size();
        while (ss >> word) 
        {
        if(hmap.find(pattern[i])==hmap.end()){
            if(hmap2.find(word)==hmap2.end()){
            hmap[pattern[i]] = word;
                hmap2[word]=pattern[i];
        }
            else
                return false;
        }
        else{
            if(hmap[pattern[i]]!=word)
                return false;
            }
             i+=1;
        }
        if(i!=size){
            return false;
        }
        return true;
    }
};