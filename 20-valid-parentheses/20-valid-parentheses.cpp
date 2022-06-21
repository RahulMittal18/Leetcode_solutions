class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> hmap;
        hmap[')'] = '(';
        hmap['}'] = '{';
        hmap[']'] = '[';
        for(int i=0; i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top()==hmap[s[i]]){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};