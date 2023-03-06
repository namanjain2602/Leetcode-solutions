class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
unordered_map<int,int>ans;
for(int i=0;i<nums.size();i++){
int k=target-nums[i];
if(ans.count(k)){
return {ans[k],i};
}
ans[nums[i]]=i;
}
return {-1,-1};
}
};