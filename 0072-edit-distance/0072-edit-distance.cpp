class Solution {
public:
  /*int solver(string &s1,string &s2,int i,int j)
  {
      if(i<0)
          return j+1;
      if(j<0)
          return i+1;
      if(s1[i]==s2[j])
          return 0+solver(s1,s2,i-1,j-1);
      else
          return 1+min({solver(s1,s2,i-1,j-1),solver(s1,s2,i,j-1),solver(s1,s2,i-1,j)}
                       );
  }
  */
    int solver(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
  {
      if(i<0)
          return j+1;
      if(j<0)
          return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
      if(s1[i]==s2[j])
          return  0+solver(s1,s2,i-1,j-1,dp);
      else
          return dp[i][j]=1+min({solver(s1,s2,i-1,j-1,dp),solver(s1,s2,i,j-1,dp),solver(s1,s2,i-1,j,dp)}
                       );
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solver(word1,word2,n-1,m-1,dp);
    }
};