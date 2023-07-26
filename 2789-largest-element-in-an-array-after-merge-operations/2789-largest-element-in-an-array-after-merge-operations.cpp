class Solution {
public:
    long long maxArrayValue(vector<int>& nums) 
    {
        vector<long long>nums1;
      for(auto x:nums)nums1.push_back(x);
        for(int i=nums1.size()-1;i>0;i--)
        {
            if(nums1[i-1]<=nums1[i])
                nums1[i-1]+=nums1[i];
        }
        return nums1[0];
    }
};