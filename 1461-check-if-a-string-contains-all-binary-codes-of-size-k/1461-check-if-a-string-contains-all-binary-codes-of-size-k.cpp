class Solution {
public:
    bool hasAllCodes(string str, int k) {
        set<string> s;
        int count = 1<<k;
        for(int i=0;i+k<=str.length();i++){
            if(s.find(str.substr(i,k)) == s.end()){
                s.insert(str.substr(i,k));
                count--;
            }
        }
        return count==0;
    }
};