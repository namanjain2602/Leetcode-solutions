//@2020B0101039
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left=0,right=1e14,ans=right;//maintaining left adn right pointers
        while(left<right){
            long long mid=(left+right)/2;
            long long ctr=0;
            for(int i=0;i<time.size();++i){
                ctr+=mid/time[i];  // checking if that mid can fultill totaltrips or not by adding all 
            //  possible no of trips performed by all buses with mid time 
                
            } 
            if(ctr>=totalTrips){
                ans=min(ans,mid); // minimising time
                right=mid;
            }else{
                left=mid+1;
            }
            
        }
        return ans;
    }
};