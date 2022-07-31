class NumArray {
public:
    int n;
    int csize;
    vector<int> csum;
    vector<int> nums;
    NumArray(vector<int>& num) {
        n = num.size();
        csize = ceil(sqrt(n));
        csum.resize(csize,0);
        for(int i=0;i<n;i++){
            nums.push_back(num[i]);
            csum[i/csize]+=num[i];
        }
    }
    
    void update(int index, int val) {
        csum[index/csize]-=nums[index];
        csum[index/csize]+=val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int chunk_start = left/csize;
        int chunk_end = right/csize;
        int sum=0;
        if(chunk_start==chunk_end){
            for(int i=left;i<=right;i++){
                sum+=nums[i];
            }
        }
        else{
            for(int i=left;i<(chunk_start+1)*csize;i++){
                sum+=nums[i];
            }
            for(int i = chunk_start+1;i<chunk_end;i++){
                sum+=csum[i];
            }
            for(int i=chunk_end*csize;i<=right;i++){
                sum+=nums[i];
            }
        }
        return sum;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */