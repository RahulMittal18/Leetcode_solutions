class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        // if(coins.size()==1) return amount%coins[0]==0 ? amount/coins[0] : -1; 
        long long int dp[coins.size()+1][amount+1];
        for(int i=1;i<=coins.size();i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++){
            dp[0][i]=INT_MAX;
            if(i!=0 and i%coins[0]==0){
                dp[1][i]=i/coins[0];
            }
            else{
                dp[1][i]=INT_MAX;
            }
        }
        
        for(int i=2;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j)
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[coins.size()][amount]==INT_MAX?-1:dp[coins.size()][amount];
        
    }
};