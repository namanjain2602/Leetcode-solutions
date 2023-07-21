class Solution {
public:
     void dfs(int i,vector<int>adj[],vector<bool>& vis)
    {
           vis[i]=true;
         for(auto it:adj[i])
         {
             if(!vis[it])
                 dfs(it,adj,vis);
         }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
       vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
                if(!vis[i])
                {
                    ans++;
                    dfs(i,adj,vis);
                }
        }
        return ans;
    }
};