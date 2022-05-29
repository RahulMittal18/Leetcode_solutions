class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int freq[n][26];
        for(int i=0;i<words.size();i++){
            for(int k=0;k<26;k++){
                freq[i][k]=0;
            }
        }
        for(int i=0;i<words.size();i++){
            for(auto c:words[i]){
                freq[i][c-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                bool flag=true;
                for(int k=0;k<26;k++){
                    if(freq[i][k]!=0 and freq[j][k]!=0){
                        flag=false;
                        break;
                    }
                }
                int l=words[i].size();
                int q=words[j].size();
                q=q*l;
                if(flag) ans=max(ans,q);
            }
        }
        return ans;
    }
};