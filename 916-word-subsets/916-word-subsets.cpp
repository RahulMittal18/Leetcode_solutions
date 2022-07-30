class Solution {
public:
    vector<int> counter(string a){
        vector<int> res(26,0);
        for(int i=0;i<a.size();i++){
            res[a[i]-'a']++;
        }
        return res;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v1(26,0);
        for(auto word : words2){
            vector<int> temp = counter(word);
            for(int k=0;k<26;k++){
                v1[k]=max(v1[k],temp[k]);
            }
        }
        vector<string> ans;
        for(auto word: words1){
            vector<int> m2 = counter(word);
            int k;
            for(k=0;k<26;k++){
                if(m2[k]<v1[k]){
                    break;
                } 
            }
            if(k==26) ans.push_back(word);
        }
        return ans;
        
    }
};