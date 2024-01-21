class Solution {
public:
    vector<int> dp;
    int maxRobbery(int i, vector<int>& nums) {
        if (i < 0) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans =
            max(nums[i] + maxRobbery(i - 2, nums), maxRobbery(i - 1, nums));
        return dp[i] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n + 1, -1);
        return maxRobbery(n - 1, nums);
    }
};