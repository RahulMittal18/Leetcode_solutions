class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string temp = countAndSay(n-1);
        string ans = "";
        int l=1;
        char c=temp[0];
        for(int i=1;i<temp.size();i++){
            if(temp[i]==temp[i-1]){
                l++;
            }
            else{
                ans+=(l+'0');
                ans+=c;
                c=temp[i];
                l=1;
            }
        }
        
        ans+=(l+'0');
        ans+=c;
        return ans;
    }
};