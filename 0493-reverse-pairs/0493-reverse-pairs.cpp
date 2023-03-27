#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<pair<double,int>, null_type, less_equal<pair<double,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set s;
        int ans = 0;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            ans += s.order_of_key({nums[i]/2.0,0}); 
            s.insert({nums[i],i});
        }
        return ans;
    }
};