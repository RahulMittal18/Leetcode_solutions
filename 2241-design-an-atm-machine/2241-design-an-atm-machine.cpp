class ATM {
public:
    
    map<int,int> mp;
    vector<long long int> arr;
    ATM() {
        arr.resize(5,0);
        mp[0]=20;
        mp[1]=50;
        mp[2]=100;
        mp[3]=200;
        mp[4]=500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            arr[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<long long int> t = arr;
        vector<int> ans(5,0);
        for(int i=4;amount!=0 && i>=0;i--){
            if(amount/mp[i]!=0){
                if(amount/mp[i]<=arr[i]){
                    arr[i]-=amount/mp[i];
                    ans[i]+=amount/mp[i];
                    amount%=mp[i];
                } 
                else{
                    amount-=(arr[i]*mp[i]);
                    ans[i]+=arr[i];
                    arr[i]=0;
                }
            } 
        }
        if(amount==0) return ans;
        else{
            arr=t;
            return {-1};
        } 
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */