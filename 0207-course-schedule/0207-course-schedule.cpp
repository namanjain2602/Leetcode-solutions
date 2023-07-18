class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int>indegree(V,0);
        vector<int>adj[V];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
	     for(int i=0;i<V;i++)
	     {
	         for(int j=0;j<adj[i].size();j++)
	         {
	             indegree[adj[i][j]]++;
	         }
	     }
	    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int>ans;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for(auto it:adj[x])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
   if(ans.size()==V)
       return true;
        return false;
    }
};