class Solution {
public:
    Solution(){
        // Base case:
        climbMethodTo[0] = 1;   // reach floor_0 by doing nothing
        climbMethodTo[1] = 1;   // reach floor_1 with one step
    }
    
    int climbStairs(int n) {
        
        // look-up table, also known as memoization
        if( climbMethodTo[n] ){
            return climbMethodTo[n];
        }

        climbMethodTo[n] = climbStairs(n-1) + climbStairs(n-2);
        
        return climbMethodTo[n];
    }
    
private:
    map<int, int> climbMethodTo;
};