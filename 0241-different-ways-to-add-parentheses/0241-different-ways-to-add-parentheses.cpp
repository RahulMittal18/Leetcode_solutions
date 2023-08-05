class Solution {
public:
    int calc(int num1,int num2,char op){
        if(op=='+') return num1+num2;
        else if(op=='-') return num1-num2;
        else return num1*num2;
    }
    vector<int> solve(int l,int r,string &s,map<pair<int,int>,vector<int>> &dp){
        vector<int> res;
        if(l>r){
            res.push_back(0);
            return res;
        }
        if(r-l<2){
            res.push_back(stoi(s.substr(l,r-l+1)));
            return res;
        }
        if(dp.find({l,r})!=dp.end()) return dp[{l,r}];
        for(int k=l;k<=r;k++){
            if(s[k]=='+' || s[k]=='-' || s[k]=='*'){
                auto left = solve(l,k-1,s,dp);
                auto right = solve(k+1,r,s,dp);

                for(auto ls:left){
                    for(auto rs:right){
                        res.push_back(calc(ls,rs,s[k]));
                    }
                }
            }
            
        }
        return dp[{l,r}]=res;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        map<pair<int,int>,vector<int>> dp;
        return solve(0,expression.size()-1,expression,dp);
    }
};