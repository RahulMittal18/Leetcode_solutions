class MinStack {
public:
    vector<pair<int,int>> st;
    int curr_min=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(curr_min>val)
            curr_min=val;
        st.push_back({val,curr_min});
    }
    
    void pop() {
        if(st.size()==1)
            curr_min=INT_MAX;
        else
            curr_min = st[st.size()-2].second;
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1].first;
    }
    
    int getMin() {
        return st[st.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */