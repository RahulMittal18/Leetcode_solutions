class Solution {
public:
    int maxVowels(string ss, int k) {
        int ans = 0;
        int l = 0;
        int n = ss.size();
        int r = 0;
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        int temp = 0;
        while(r<n){
            if(s.count(ss[r])){
                temp++;
            }
            while(r-l+1>k){
                if(s.count(ss[l])) temp--;
                l++;
            }
            ans = max(ans,temp);
            r++;
        }
        return ans;
    }
};