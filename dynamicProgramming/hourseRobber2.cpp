class Solution {
public:
    int maxRobbedAmount(vector<int> &nums, vector<int> &dp, int n, int i = 0){
        if(i > n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int robIt = nums[i] + maxRobbedAmount(nums, dp, n, i+2);
        int dontRob = maxRobbedAmount(nums, dp, n, i+1);

        int ans = max(robIt, dontRob);
        return dp[i] = ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int i = 0;
        int n = nums.size();
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
        return max(maxRobbedAmount(nums, dp1, n-2, 0), maxRobbedAmount(nums, dp2, n-1, 1));
    }
};