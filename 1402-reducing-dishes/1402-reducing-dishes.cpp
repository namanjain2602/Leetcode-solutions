class Solution {
public:
   
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end(),greater<int>());
        int ans = max(v[0],0), sum = v[0],i,n=v.size();
        for(i = 1; i < n; i++){
            v[i] += v[i-1];
        }
        for(i = 1; i < n; i++){
            sum += v[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};