class Solution {
public:
    
    
    bool pal(int num){
        string s1 = to_string(num);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long med;
        if(n%2==0){
            med = (nums[n/2] + nums[(n-1)/2])/2;
        }
        else{
            med = nums[n/2];
        }
        // cout<<med<<endl;
        int p1=med,p2=med;
        while(!pal(p1) && p1>=0){
            p1--;
        }
        while(!pal(p2) && p2<1e9) p2++;
        
        long long ans = 1e18;
        long long temp =0;
        cout<<p1<<" "<<p2<<endl;
        if(p1>=0){

            for(int i=0;i<n;i++) temp +=abs(nums[i]-p1);
            
        }
        ans = min(ans,temp);
        temp =0;
        if(p2<1e9){
        for(int i=0;i<n;i++) temp +=abs(nums[i]-p2);
                            ans = min(ans,temp);

        }
        return ans;
    }

};