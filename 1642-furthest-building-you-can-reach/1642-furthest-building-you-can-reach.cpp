class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> bricksq;
        int i=0;
        while(i<heights.size()-1){
            if(heights[i+1]>heights[i]){
                int diff = heights[i+1]-heights[i];
                if(diff<=bricks){
                    bricksq.push(diff);
                    bricks-=diff;
                }
                else if(ladders-- > 0){
                    if(bricksq.size() && bricksq.top()>diff){
                        bricks+=(bricksq.top()-diff);
                        bricksq.pop();
                        bricksq.push(diff);
                    }
                }
                else{
                    break;
                }
            }
            i++;
        }
        return i;
    }
};