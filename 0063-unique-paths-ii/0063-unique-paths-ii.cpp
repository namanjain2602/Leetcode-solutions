class Solution {
public:
     int solver(vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp,int i,int j)
     {
         if(i==obstacleGrid.size()||j==obstacleGrid[0].size())
             return 0;
         if(obstacleGrid[i][j]==1)
             return 0;
         if(i==obstacleGrid.size()-1&&j==obstacleGrid[0].size()-1)
             return 1;
         if(dp[i][j]!=-1)
             return dp[i][j];
         return dp[i][j]=solver(obstacleGrid,dp,i+1,j)+solver(obstacleGrid,dp,i,j+1);
     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));
       return solver(obstacleGrid,dp,0,0);
    }
};