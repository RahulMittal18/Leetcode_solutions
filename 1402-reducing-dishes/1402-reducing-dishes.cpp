class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int maxx=0;
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<s.size();i++){
            if(s[i]>0){
                v1.push_back(s[i]);
            }
            else{
                v2.push_back(s[i]);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int x=v2.size();
        while(x+1){
            int j=1;
            int ans=0;
            for(int i=x;i<v2.size();i++){
                ans+=j*v2[i];
                j++;
            }
            for(int i=0;i<v1.size();i++){
                ans+=j*v1[i];
                j++;
            }
            maxx=max(ans,maxx);
            x--;
        }
    return maxx;}
};
    