class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s;
        for(auto x:deadends) s.insert(x);
        queue<string> q;
        q.push("0000");
        if(s.count("0000")!=0) return -1;
        s.insert("0000");

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string popped = q.front();

                q.pop();
                if(popped==target) return ans;
                for(int i=0;i<4;i++){
                    string temp = popped.substr(0,4);
                    if(temp[i]=='9') temp[i]='0';
                    else temp[i]+=1;
                    if(s.count(temp)==0){
                        q.push(temp);
                        s.insert(temp);
                    } 
                    
                    string temp2 = popped.substr(0,4);
                    if(temp2[i]=='0') temp2[i]='9';
                    else temp2[i]-=1;
                    if(s.count(temp2)==0){
                        q.push(temp2);
                        s.insert(temp2);
                    } 
                }
            }
            ans++;
        }
        return -1;
    }
};