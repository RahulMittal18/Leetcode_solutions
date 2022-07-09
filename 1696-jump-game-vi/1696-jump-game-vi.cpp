class Solution {
public:
    
    int solve(vector<int> &nums, int i,int k,int dp[]){
        int n = nums.size();
        if(i==n-1){
            return nums[i];
        }
        if(dp[i]!=-1) return dp[i];
        int temp = INT_MIN;
        for(int j=i+1;j<=min(n-1,i+k);j++){
            temp = max(temp,solve(nums,j,k,dp));
        }
        return dp[i]=nums[i]+temp;
    }
    
    
    // int maxResult(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int dp[n];
    //     memset(dp,-1,sizeof dp);
    //     int x = solve(nums,0,k,dp);
    //     // for(int i=0;i<n;i++) cout<<dp[i]<<" \n"[i==n-1];
    //     return x;
    // }
    
    
    
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         // int ans = 0;
//         int prev = -1e6;
//         deque<int> dq;
//         int i =0;
//         while(i<k){
//             while(!dq.empty() && nums[dq.back()]<=nums[i]){
//                 dq.pop_back();
//             }
            
//             dq.push_back(i);
//             i++;
//         }
//         vector<int> ans;
//         while(i<n){
//             // cout<<i<<" "<<ans<<endl;
//             if(dq.front()!=prev) {
//                 ans.push_back(dq.front());
//                 prev = dq.front();
//             }
//             while(!dq.empty() && nums[dq.back()]<=nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//             while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
//             i++;
//         }
//         ans.push_back(n-1);

//         // for(int i=0;i<ans.size();i++){
//         //     cout<<ans[i]<<" \n"[i==ans.size()-1];
//         // }
//         int res=nums[ans[0]]+nums[ans[ans.size()-1]];
//         prev = 0;
//         for(int i=1;i<ans.size()-1;i++){
//             res+=nums[ans[i]];
//             if(nums[ans[i]]<0 && ans[i+1]-prev<=k){
//                 res-=nums[ans[i]];
//             }
//             else{
//                 prev=ans[i];
//             }
//         }
//         return res;
//     }
    int maxResult(vector<int>& nums, int k) {
	vector<int> dp(size(nums));
	dp[0] = nums[0];
	deque<int> q{ 0 };
	for(int i = 1; i < size(nums); i++) {
		if(q.front() < i - k) q.pop_front();         // can't reach current index from index stored in q     
		dp[i] = nums[i] + dp[q.front()];             // update max score for current index
		while(!q.empty() && dp[q.back()] <= dp[i])   // pop indices which won't be ever chosen in the future
		    q.pop_back();
		q.push_back(i);                              // insert current index
	}
	return dp.back();
}
};