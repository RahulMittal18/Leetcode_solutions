class Solution {
    unordered_map<char,char> par;
public:

    char parent(char c){
        if(par[c]==c) return c;
        return par[c]=parent(par[c]);
    }
    
    void unite(char a,char b){
        par[a]=b;
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++) par['a'+i] = i+'a';
        for(auto &eqn : equations){
            char a = eqn[0];
            char b = eqn[3];
            
            if(eqn[1] == '='){
                char parA = parent(a);
                char parB = parent(b);
                if(parA!=parB)
                unite(parA,parB);
            }
        }
        for(auto &eqn : equations){
            char a = eqn[0];
            char b = eqn[3];
            
            if(eqn[1] == '!'){
                char parA = parent(a);
                char parB = parent(b);
                if(parA==parB)
                return false;
            }
        }
        return true;
    }
};