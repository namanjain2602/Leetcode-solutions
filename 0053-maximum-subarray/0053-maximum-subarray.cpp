class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            maxi=max(maxi,s);
            if(s<0)
                s=0;
        }
        return maxi;
    }
};