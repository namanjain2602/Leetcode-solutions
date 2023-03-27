class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<vector<int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j,0});
            }
        }
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        while(!q.empty())
        {
            auto it=q.front();
            int x=it[0];
            int y=it[1];
            int z=it[2];
            q.pop();
           for(int i=0;i<=3;i++)
           {
               int xt=x+dr[i];
               int yt=y+dc[i];
               if(xt>=0&&yt>=0&&xt<m&&yt<n&&grid[xt][yt]==1)
               {
                   ans=max(ans,z+1);
                   grid[xt][yt]=2;
                   q.push({xt,yt,z+1});
               }
           }
        }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1)
                        return -1;
                }
            }
        return ans;
    }
};