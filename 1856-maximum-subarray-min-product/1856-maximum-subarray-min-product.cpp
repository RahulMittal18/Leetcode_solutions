class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        
        stack<int> st;
        long long ans = 0;
        for(int i=0;i<=n;i++){
            while(st.size() && (i==n || nums[st.top()] > nums[i])){
                int x = st.top();
                st.pop();
                long long sum = pre[i];
                if(st.size()) sum -= pre[st.top()+1];
                ans = max(ans, nums[x]*sum);
            }
            
            st.push(i);
        }
        return ans%1000000007;
    }
};