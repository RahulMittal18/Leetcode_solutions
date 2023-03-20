class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();
        int i=0;
        while(i<n){
            if(flowerbed[i]==1) {
                i+=2;
                continue;
            }
            if(i==n-1) {
                i+=2;
                k--;
                continue;
            }
            if(flowerbed[i]==0 && flowerbed[i+1]==0){
                k--;
                i+=2;
            }        
            else{
                i++;
            }
        }
        return k<=0;
    }
};