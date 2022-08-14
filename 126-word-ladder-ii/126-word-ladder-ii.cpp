class Solution {
public:
    
    
    void dfs(string &beginWord,string &endWord,vector<string>&path, vector<vector<string>>&ans,unordered_map<string,vector<string>>&adj ){
        path.push_back(beginWord);
        if(beginWord==endWord){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto w:adj[beginWord]){
            dfs(w,endWord,path,ans,adj);
        }
        path.pop_back();
    }
    
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        if(s.count(endWord)==0) return {};
        unordered_map<string,int> level;
        unordered_map<string,vector<string>> adj;
        queue<string> q;
        q.push(beginWord);
        level[beginWord]=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto popped = q.front();
                q.pop();
                for(int i=0;i<popped.size();i++){
                    for(int j=0;j<26;j++){
                        string temp = popped;
                        temp[i] = 'a' + j;
                        if(s.count(temp)==1){
                            if(level.find(temp)==level.end()){
                                q.push(temp);
                                level[temp]=1+level[popped];
                                adj[temp].push_back(popped);
                            }
                            else if(level[temp]==1+level[popped]){
                                adj[temp].push_back(popped);
                            }
                        }
                    }
                }
            }
        }
        
        vector<vector<string>> ans;
        vector<string> path;
        dfs(endWord,beginWord,path,ans,adj);
        for(auto &k:ans){
            reverse(k.begin(),k.end());
        }
        return ans;
    }
};
    
