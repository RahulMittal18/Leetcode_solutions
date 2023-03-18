class BrowserHistory {
private:
    stack<string> fwd,bck;
public:
    BrowserHistory(string homepage) {
        bck.push(homepage);
    }
    
    void visit(string url) {
        bck.push(url);
        while(!fwd.empty()) fwd.pop();
    }
    
    string back(int steps) {
        while(bck.size()>1 && steps>0){
            fwd.push(bck.top());
            bck.pop();
            steps--;
        }
        return bck.top();
    }
    
    string forward(int steps) {
        string ans = "";
        while(fwd.size() && steps>0){
            bck.push(fwd.top());
            ans = fwd.top();
            fwd.pop();
            steps--;
        }
        if(!fwd.size()) return bck.top();
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */