class Solution {
public:
    
    vector<int> evenOddBit(int n) {
       int a=0;
        int b=0;
        int c=0;
        while(n)
        {
            if(n&1)
            {
                if(c&1)
                a++;
                else
                b++;
                c++;
            }
            else
                c++;
            n/=2;
        }
        return {b,a};
    }
};