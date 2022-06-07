class Solution {
public:
    int solve(vector<int> cost,int n){
        if(n<0) return 0;
        if(m.find(n)!=m.end()) return m[n];
        int temp = min(solve(cost,n-2),solve(cost,n-1));
        m[n]=temp+cost[n];
        return temp + cost[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost,cost.size()-1),solve(cost,cost.size()-2));
    }
    
private:
    map<int,int> m;
};