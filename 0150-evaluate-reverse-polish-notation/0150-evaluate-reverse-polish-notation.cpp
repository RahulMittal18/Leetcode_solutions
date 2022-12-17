class Solution {
public:
    bool isOperator(string &s){
        if(s.length()==1){
            if(s=="+" || s=="-" || s=="*" || s=="/") return true;
        }
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(isOperator(tokens[i])){
                long op2 = st.top();
                st.pop();
                long op1 = st.top();
                st.pop();
                if(tokens[i]=="+") st.push(op1+op2);
                else if(tokens[i]=="-") st.push(op1-op2);
                else if(tokens[i]=="*") st.push(op1*op2);
                else st.push(op1/op2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};