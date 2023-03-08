class Solution {
public:
   long long gethours(vector<int>& piles, int h) {
       long long  answr=0;
        for (int i=0;i<piles.size();i++) {
        int hours=ceil(piles[i] / (double)h);
            answr+=hours;
        }
        return answr;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *(max_element(piles.begin(),piles.end()));
        int ans=-1;
         //================================================================
        while (l <= r) {
            int m = l + (r - l)/2;
           long long hrs=gethours(piles,m);
            if (hrs<=h)
            {
                ans=m;
             r = m - 1;
            }
            else l = m+1;
        }
         //================================================================
        return ans;
    }
};