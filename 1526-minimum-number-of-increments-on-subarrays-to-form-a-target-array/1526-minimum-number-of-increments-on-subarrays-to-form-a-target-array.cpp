class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int curr = 0;
        int n = target.size();
        for(int i=0;i<n;i++){
            if(curr<target[i]){
                ans+=(target[i]-curr);
            }
            curr = target[i];  
        }
        return ans;
    }
};