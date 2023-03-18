class BrowserHistory {
public:
    vector<string> URLsHistory;
    int currURL, lastURL;
    
    BrowserHistory(string homepage) {
        URLsHistory.push_back(homepage);
        currURL = 0;
        lastURL = 0;
    }
    
    void visit(string url) {
        currURL++;
        if (URLsHistory.size() > currURL) {
          // We have enough space in our array to overwrite an old 'url' entry with new one. 
            URLsHistory[currURL] = url;
        }
        else {
            // We have to insert a new 'url' entry at the end.
            URLsHistory.push_back(url);
        }
        // Now this will be out last url 
        lastURL = currURL;
    }
    
    string back(int steps) {
      // move currURL to the leftmost place
        currURL = max(0, currURL - steps);
        return URLsHistory[currURL];
    }
    
    string forward(int steps) {
      // move currURL to the rightmost place
        currURL = min(lastURL, currURL + steps);
        return URLsHistory[currURL];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */