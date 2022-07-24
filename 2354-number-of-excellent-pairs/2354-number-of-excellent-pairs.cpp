class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto e:st){
            int c=0;
            for(int i=0;i<32;i++){
                if(e&(1<<i)) c++;
            }
            mp[c]++;
        }
        vector<pair<int,int>> arr;
        
        long long ans = 0;
        for(auto j:mp){
            arr.push_back({j.first,j.second});
            if((j.first)*2>=k) ans+=(j.second*j.second);
        }
        
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<long long> p(n);
        p[0]=arr[0].second;
        for(int i=1;i<n;i++){
            p[i]=p[i-1]+arr[i].second;
        }


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j].first+arr[i].first>=k){
                    ans+= 2*(p[n-1]-p[j-1])*(arr[i].second);
                    break;
                }
            }
        }
        return ans;
        
    }
};