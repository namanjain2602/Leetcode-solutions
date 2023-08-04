//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
//     int catalan(int n,vector<int>& dp)
// {
//     if(n==0||n==1)
//         return 1;
//     if(dp[n]!=0)
//         return dp[n];
//     else{
//             for(int i=0;i<n;i++)
//         dp[n]+=catalan(i,dp)*catalan(n-i-1,dp);
//     return dp[n];
//     }
// }
    int findCatalan(int n) 
    {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<n;i++)
        dp[i][0]=1;
  for(int col=1;col<=n;col++)
  {
      int rows=col-1;
      dp[rows][col]=dp[rows][col-1]%1000000007;
      for(int row=rows+1;row<n;row++)
        dp[row][col]=(dp[row][col-1]+dp[row-1][col])%1000000007;
  }
  return (dp[n-1][n])%1000000007;
  
//   vector<int>dp(n+1,0);
//   return catalan(n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends