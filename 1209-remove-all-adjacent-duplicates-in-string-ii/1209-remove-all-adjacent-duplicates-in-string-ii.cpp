class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'Z',0});
        for(char c:s){
            if(c!=st.top().first){
                st.push({c,1});
            }
            else{
                st.top().second++;
                if(st.top().second==k)
                    st.pop(); 
            }
        }
        
        string ans="";
        while(st.size()!=1){
            ans.append(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};