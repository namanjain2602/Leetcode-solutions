class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        map<int, int> mp;
    mp[0] = 1;
    bool flag = false;
    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
 
     
        if (nums[i] < k)
            sum--;
        else if (nums[i] > k)
            sum++;
        if (nums[i] == k)
            flag = true;
        
        
        if (flag)
            ans += mp[sum] + mp[sum - 1];
        else
            mp[sum]++;
    }
 
    return ans;
    }
};