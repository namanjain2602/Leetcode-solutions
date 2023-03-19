class Solution {
public:
    int distMoney(int money, int children) {
       int money_rem = money - children;  
        if(money_rem < 0)
            return -1;
        int cnt_7 = money_rem/7;
        int val_other = money_rem%7;
        
        if(cnt_7 < children){
            int rem_child = children - cnt_7;
            if(val_other==3 && rem_child==1)
                return max(0, cnt_7-1);
            else
                return cnt_7;
        }else if(cnt_7 > children){
            return children-1;
        }else{
            if(val_other==0)
                return cnt_7;
            else
                return cnt_7 - 1;
        }
        
    }
};