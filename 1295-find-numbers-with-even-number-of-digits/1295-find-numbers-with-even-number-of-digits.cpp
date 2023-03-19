class Solution {
public:
    int countdigit(int n)
    {
        int cnt=0;
        while(n>0)
        {
            cnt++;
            n/=10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto i:nums)
        {
            int c=countdigit(i);
            if(c%2==0)
                ans++;
        }
        return ans;
    }
};