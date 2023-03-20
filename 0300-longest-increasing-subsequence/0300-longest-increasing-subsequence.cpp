class Solution {
public:
    int solver(vector<int>& nums,int prev,int curr,int n,vector<vector<int>>&dp)
    {
        if(curr==n)
            return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int len=0+solver(nums,prev,curr+1,n,dp);
        if(prev==-1||(nums[curr]>nums[prev]))
            len= max(len,1+solver(nums,curr,curr+1,n,dp));
         return dp[curr][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solver(nums,-1,0,n,dp);
    }
};