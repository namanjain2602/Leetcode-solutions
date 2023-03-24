class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>&adj, vector<bool>& visited, int& ans, int currNode)
    {
        visited[currNode] = true;
        for (pair<int, int>adjNode : adj[currNode])
        {
            if (visited[adjNode.first]) continue; 
            bool isEdgeOutward = (adjNode.second == 1); 
            if (isEdgeOutward) ans++; 
            dfs(adj, visited, ans, adjNode.first);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int, int>>>adj(n);
        for(vector<int>connection : connections)
        {
            adj[connection[0]].push_back({connection[1], 1}); 
            adj[connection[1]].push_back({connection[0], -1}); 
        }
        //===========================================================
        vector<bool>visited(n, false);
        int ans = 0;
        dfs(adj, visited, ans, 0);
        return ans;
    }
};