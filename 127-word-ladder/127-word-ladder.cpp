class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(auto x:wordList) s.insert(x);
        set<string> vis;
        vis.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            
            int n = q.size();

            while(n--){
                string popped = q.front();
                q.pop();
                if (popped==endWord) return ans;
                for(int i=0;i<popped.size();i++){
                    for(int j=0;j<26;j++){
                    string temp = popped;
                    temp[i] = 'a' + j;
                    if(vis.count(temp)==0 and s.count(temp)!=0){
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
                }
            }
            ans++;
        }
        return 0;
    }
};