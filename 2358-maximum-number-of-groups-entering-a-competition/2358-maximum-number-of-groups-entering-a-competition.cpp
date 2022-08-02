class Solution {
public:
    
    bool check(long long int x,long long int n){
        return (x*(x+1))/2 <= n;
    }
    
    int maximumGroups(vector<int>& grades) {
        int l = 0;
        int n = grades.size();
        int r = n;
        int ans = 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            // cout<<l<<" "<<r<<" "<<" "<<mid<<" "<<check(mid,n)<<endl;
            if(check(mid,n)){
                l=mid+1;
                ans = mid;
            }
            else{
                r=mid-1;
            }
        }
        // if(check(l,n)) return l-1;
        return ans;
    }
};