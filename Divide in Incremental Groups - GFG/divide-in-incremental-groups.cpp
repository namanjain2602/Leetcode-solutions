//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
          int ways(int N,int K,int c,vector<vector<vector<int>>>& dp){
        if(K == 1){
            return 1;
        }
        else if(dp[N][K][c] != -1){
            return dp[N][K][c];
        }
        else{
            int ans = 0;
            for(int j = max(1,c); j <= N; j++){
                if(N-j >= j){
                    ans += ways(N-j,K-1,j,dp);
                }
            }
            return dp[N][K][c] = ans;
        }
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(K+1,vector<int>(N+1,-1)));
        return ways(N,K,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends