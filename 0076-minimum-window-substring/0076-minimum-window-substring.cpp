class Solution {
public:
    string minWindow(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        string ans = "";
        int len = INT_MAX;
        string res = "";
        if(lenS<lenT) return ans;
        
        vector<int> freq(60,0);
        int i = 0;
        while(i<lenT){
            freq[t[i++]-65]++;
        }
        int l = 0;
        int r = 0;
        while(r<lenS){
            freq[s[r]-65]--;
            bool contains = true;
            for(int i=0;i<60;i++){
                if(freq[i]>0) contains=false;
            }
            if(contains){
                if(len>r-l+1) {
                    res =s.substr(l,r-l+1);
                    len = res.size();
                }
                
                while(l<r){
                    freq[s[l++]-65]++;
                    bool check = true;
                    for(int i=0;i<60;i++){
                        if(freq[i]>0) check=false;
                    }
                    if(!check) break;
                    if(len>r-l+1) {
                        res = s.substr(l,r-l+1);
                        len = res.size();  
                    } 
                }
            }
            r++;
        }
        return res;
    }
};