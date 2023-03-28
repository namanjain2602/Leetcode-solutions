class Solution {
public:
    int solver(int i,vector<int>& days, vector<int>& costs,vector<int>&dp)
               {
                   if(i>=days.size())
                       return 0;
                   if(dp[i]!=-1)
                       return dp[i];
                int up1=upper_bound(days.begin(),days.end(),days[i]+1-1)-days.begin();
                   int ans1=solver(up1,days,costs,dp)+costs[0];
                   int up2=upper_bound(days.begin(),days.end(),days[i]+7-1)-days.begin();
                   int ans2=solver(up2,days,costs,dp)+costs[1];
                   int up3=upper_bound(days.begin(),days.end(),days[i]+30-1)-days.begin();
                   int ans3=solver(up3,days,costs,dp)+costs[2];
                   return dp[i]=min({ans1,ans2,ans3});
               }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int>dp(days.size()+1,-1);
        return solver(0,days,costs,dp);
    }
};