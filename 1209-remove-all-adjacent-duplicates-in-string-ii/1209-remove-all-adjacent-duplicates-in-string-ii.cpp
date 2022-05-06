class Solution {
public:
    string removeDuplicates(string s, int k) {
        char prev = 'A';
        stack<pair<char,int>> st;
        for(char c:s){
            if(c!=prev){
                st.push({c,1});
                prev=c;
            }
            
            else{
                if(st.top().second+1==k){
                    for(int j=1;j<k;j++){
                        st.top().second-=1;
                    if(st.top().second==0)
                        st.pop();
                    }
                    if(!st.empty())
                        prev=st.top().first;
                    else
                        prev='A';
                }
                else{
                    st.top().second+=1;
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+= st.top().first;
            st.top().second-=1;
            if(st.top().second==0) st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};