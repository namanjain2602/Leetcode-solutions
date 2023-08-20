class Solution {
public:
    int minimumSum(int n, int k) {
        set<int>s;
        int i=1;
        int ans=0;
        while(s.size()<n)
        {
            if(s.count(k-i))
            {
                i++;
                continue;
            }
            s.insert(i);
            i++;
        }
        for(auto i:s)
            ans+=i;
        return ans;
    }
};