class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<int,string> mp;
        unordered_map<string,int> wordset;
        for(auto word:words) wordset[word]++;
        int word_size = words[0].size();
        int i=0;
        int l = word_size*words.size();
        int n = s.size();
        for(int i=0;i+word_size<=n;i++){
            string w = s.substr(i,word_size);
            if(wordset.count(w)==1) mp[i]=w;
        }
        
        vector<int> result;
        for(int i=0;i+l<=n;i++){
            unordered_map<string,int> tempmap;
            int j=i;
            int count=0;
            while(j<n){
                if(mp[j]!=""){
                    if(tempmap[mp[j]]==wordset[mp[j]]){
                        break;
                    }
                    else{
                        tempmap[mp[j]]++;
                        count++;
                    }
                }
                else{
                    break;
                }
                if(count==words.size()){
                    result.push_back(i);
                    break;
                }
                j+=word_size;
            }
        }
        return result;
    }
};