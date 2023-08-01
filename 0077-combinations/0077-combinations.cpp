class Solution {
public:
    void solve(vector<int>&v,vector<vector<int>>&ans,int n,int k)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        if(n==0)
            return;
        v.push_back(n);
        solve(v,ans,n-1,k);
        v.pop_back();
        solve(v,ans,n-1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(v,ans,n,k);
        return ans;
    }
};