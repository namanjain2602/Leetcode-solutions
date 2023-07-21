class Solution {
public:
    bool judgeCircle(string moves) {
        int u=0,d=0,r=0,l=0;
        for(auto i:moves)
        {
            if(i=='U')
                u++;
            if(i=='D')
                d++;
            if(i=='R')
                r++;
            if(i=='L')
                l++;
        }
        if(u==d&&r==l)
            return true;
        return false;
    }
};