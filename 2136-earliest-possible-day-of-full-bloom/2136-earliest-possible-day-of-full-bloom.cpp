class Solution {
public:
        bool static comp(vector<int> &a,vector<int>&b){
            return a[1]>b[1];
        }

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans = 0;
        int plant_time = 0;
        int grow_time=0;
        vector<vector<int>> arr;
        
        for(int i=0;i<plantTime.size();i++){
            arr.push_back({plantTime[i],growTime[i]});
        }
        sort(arr.begin(),arr.end(),comp);
        for(int i=0;i<plantTime.size();i++){
            ans = max(ans,plant_time+arr[i][0]+arr[i][1]);
            plant_time+=arr[i][0];
        }
        return ans;
    }
};