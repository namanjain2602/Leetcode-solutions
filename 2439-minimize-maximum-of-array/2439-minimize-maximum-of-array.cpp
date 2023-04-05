class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0;
        long answr = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            answr = max(answr, (sum + i) / (i + 1));
        }
        return (int)answr;
    }
};