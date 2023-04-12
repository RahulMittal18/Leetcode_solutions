class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        string dir = "";
        for(int i=0;i<n;i++){
            if(path[i]!='/'){
                dir.push_back(path[i]);
            }
            else{
                // cout<<dir<<endl;
                int s = dir.size();
                if(s==1){
                    if(dir[0]!='.') st.push(dir);
                }
                else if(s==2){
                    if(dir==".."){
                        if(st.size()) st.pop();
                    }
                    else{
                        st.push(dir);
                    }
                }
                else if(s>2){
                    st.push(dir);
                }
                dir="";
            }
        }
         int s = dir.size();
                if(s==1){
                    if(dir[0]!='.') st.push(dir);
                }
                else if(s==2){
                    if(dir==".."){
                        if(st.size()) st.pop();
                    }
                    else{
                        st.push(dir);
                    }
                }
                else if(s>2){
                    st.push(dir);
                }
        string ans="";
        stack<string> st2;
        while(st.size()){
            st2.push(st.top());
            st.pop();
        }
        while(st2.size()){
            ans.push_back('/');
            for(char c:st2.top()){
                ans.push_back(c);
            }
            st2.pop();
        }
        return ans.size()>0?ans:"/";
    }
};