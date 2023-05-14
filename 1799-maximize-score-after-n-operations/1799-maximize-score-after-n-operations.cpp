class Solution {
public:
    int solve(int cnt,int i,vector<int>&nums,int n,vector<bool>&bits,int temp,int &ans,
        unordered_map<vector<bool>,int> &dp){
        // cout<<temp<<endl;
        // if(cnt>n/2) return temp;
        if(dp.count(bits)) return dp[bits];
        int a = 0;
        for(int ii=0;ii<n-1;ii++){
            if(!bits[ii]){
                bits[ii]=true;
                for(int k=ii+1;k<n;k++){
                    if(ii!=k && !bits[k]){
                        bits[k]=true;
                        int u = cnt* __gcd(nums[ii],nums[k]);
                        int v = solve(cnt+1,i+1,nums,n,bits,temp,ans,dp);
                        a=max(a,v+u);
                        bits[k]=false;
                        
                    }
                }
                bits[ii]=false;

            }
        }
        return dp[bits]=a;
    }
    
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> bits(n,false);
        int temp = 0;
        int ans = 0;
        int cnt = 0;
        unordered_map<vector<bool>,int> dp;
        return solve(cnt+1,0,nums,n,bits,temp,ans,dp);
        
    }
};