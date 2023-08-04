//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long getNthPentagonalNum(long long n) {
       return n*(n-1)+(n*(n+1))/2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        
        cin>>n;

        Solution ob;
        cout << ob.getNthPentagonalNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends