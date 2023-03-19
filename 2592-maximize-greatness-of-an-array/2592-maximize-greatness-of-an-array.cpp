class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int n=nums.size();
        int answr=0;
        int j=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[j])
            {
                j--;
                answr++;
            }
        }
        return answr;
    }
};