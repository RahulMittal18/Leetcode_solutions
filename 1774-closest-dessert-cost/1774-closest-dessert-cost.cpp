class Solution {
public:
    int ans;
    void helper(vector<int>& toppingCosts,int& temp,int i,int& target){
        if(i==toppingCosts.size() || temp>target){
            if(abs(ans-target)>abs(temp-target)) ans = temp;
            else if(abs(ans-target)==abs(temp-target)) ans = min(ans,temp);
            return;
        }
        
        for(int j=0;j<=2;j++){
            temp+=(j*toppingCosts[i]);
            if(abs(ans-target)>abs(temp-target)) ans = temp;
            else if(abs(ans-target)==abs(temp-target)) ans = min(ans,temp);
            helper(toppingCosts,temp,i+1,target);
            temp-=(j*toppingCosts[i]);
        }
    }
    
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        ans = 1e8;
        for(int i=0;i<baseCosts.size();i++){
            int temp = baseCosts[i];
            helper(toppingCosts,temp,0,target);
        }
        return ans;
    }
};