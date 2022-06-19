class trie{
   
        trie *ch[26];
        vector<string> s;
public: 
    trie(){
        memset(ch,0,sizeof(ch));
    }
    
    void insert (string p){
        trie* node=this;
        for(auto x:p){
            if(!node->ch[x-'a'])
                node->ch[x-'a']=new trie();
            node=node->ch[x-'a'];
            node->s.push_back(p);
        }
    }
    
    vector<string> search(string s){
        trie* node=this;
        vector<string> v; 
        for(char c: s){
            if(!node->ch[c-'a'])
                return v;
            node=node->ch[c-'a'];
        }
        return node->s;
    }
    
    };

class Solution {
public:
    trie root;
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        for(auto x: p){
            root.insert(x);
        }
        vector<vector<string>> ans;
        for(int i=1;i<=s.size();i++){
            string k=s.substr(0,i);
            vector<string> v=root.search(k);
            sort(v.begin(),v.end());
            if(v.size()<=3){
                
                ans.push_back(v);
            }
            else{
                vector<string> l(3);
                copy(v.begin(),v.begin()+3,l.begin());
                ans.push_back(l);
            }
        }
        return ans;
    }
};