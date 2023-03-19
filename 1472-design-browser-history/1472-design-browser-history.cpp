class BrowserHistory {
public:
    string history[105] = {};
    int index = 0;
    int end = 0;
    
    BrowserHistory(string homepage) {   
        history[index] = homepage;
    }
    
    void visit(string url) {
        history[++index] = url;
        end = index;
    }
    
    string back(int steps) {
        index = max(index - steps, 0);
        return history[index];
    }
    
    string forward(int steps) {
        index = min(index + steps, end);
        return history[index];
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */