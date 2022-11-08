class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto c:s){
            if(st.size() && (st.top()==c+32 || st.top()==c-32)){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string ans="";
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};