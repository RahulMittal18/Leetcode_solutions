class TextEditor {
    deque<char> before;
    deque<char> after;
    
    void fillString(deque<char>& before, string& s) {
        int maxLen = 10;
        while (before.size() && maxLen --) {
            s.push_back(before.back());
            before.pop_back();
        }
        reverse(s.begin(), s.end());
        for (auto &ch: s) {
            before.push_back(ch);
        }
    }
    
public:
    TextEditor() {
    }
    
    void addText(string text) {
        for (auto &ch: text) {
            before.push_back(ch);
        }
    }
    
    int deleteText(int k) {
        int deleted = 0;
        while(before.size() && k --) {
            before.pop_back();
            deleted ++;
        }
        return deleted;
    }
    
    string cursorLeft(int k) {
        while (before.size() && k --) {
            char ch = before.back();
            after.push_front(ch);
            before.pop_back();
        }
        string s;
        fillString(before, s);
        return s;
    }
    
    string cursorRight(int k) {
        while (after.size() && k --) {
            char ch = after.front();
            before.push_back(ch);
            after.pop_front();
        }
        string s;
        fillString(before, s);
        return s;
    }
};