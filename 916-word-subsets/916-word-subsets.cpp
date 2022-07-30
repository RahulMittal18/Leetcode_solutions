class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v1(26,0);
        for(int i=0;i<words2.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<words2[i].size();j++){
                temp[words2[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(temp[k]>v1[k]) v1[k]=temp[k];
            }
        }
        vector<string> ans;
        for(int i=0;i<words1.size();i++){
            vector<int> m2(26,0);
            for(auto c:words1[i]){
                m2[c-'a']++;
            }
            int k;
            for(k=0;k<26;k++){
                if(m2[k]<v1[k]){
                    break;
                } 
            }
            if(k==26) ans.push_back(words1[i]);
        }
        return ans;
        
    }
};