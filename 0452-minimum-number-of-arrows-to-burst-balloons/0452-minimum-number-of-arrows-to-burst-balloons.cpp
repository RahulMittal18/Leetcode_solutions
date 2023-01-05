class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1;
        int n = points.size();
        int st = points[0][0];
        int end = points[0][1];
        for(int i=1;i<n;i++){
            if(end<points[i][0]) {
                ans++;
                st = points[i][0];
                end = points[i][1];
            }
            else{
                st = points[i][0];
                end = min(points[i][1],end);
            }
        }
        return ans;
    }
};