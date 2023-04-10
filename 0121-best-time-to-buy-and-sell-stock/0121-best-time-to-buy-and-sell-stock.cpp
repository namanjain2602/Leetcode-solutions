class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto i:prices)
        {
            mini=min(i,mini);
            maxi=max(maxi,i-mini);
        }
        return maxi;
    }
};