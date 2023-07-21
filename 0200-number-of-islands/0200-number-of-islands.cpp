class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>& vis)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||vis[i][j])
            return ;
        if(!vis[i][j]&&grid[i][j]=='1'){
            vis[i][j]=true;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
        dfs(i,j+1,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};