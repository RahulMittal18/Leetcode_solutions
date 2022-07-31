class NumArray {
public:
    int n;
    int psize;
    vector<int> sq;
    vector<int> nums;
    NumArray(vector<int>& num) {
        n = num.size();
        psize = ceil(sqrt(n));
        sq.resize(psize,0);
        for(int i=0; i<n;i++){
            nums.push_back(num[i]);
            sq[i/psize]+=num[i];
        }
    }
    
    void update(int index, int val) {
        sq[index/psize]-=(nums[index]-val);
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        // cout<<psize<<endl;
        int bstart = left/psize;
        int bend = right/psize;
        int ans = 0;
        // cout<<bstart<<bend<<endl;
        if(bstart==bend) {
            for(int i =left;i<=right;i++) ans+=nums[i];
        }
        else{
            for(int i=left;i<(bstart+1)*psize;i++) ans+=nums[i];
            for(int i=bstart+1;i<=bend-1;i++) ans+=sq[i];
            for(int i=bend*psize; i<=right;i++) ans+=nums[i];
        }
        return ans;        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */