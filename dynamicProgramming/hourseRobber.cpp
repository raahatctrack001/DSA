class Solution {
public:
    int maxRobbedAmount(vector<int> &nums, vector<int> &dp, int i = 0){
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int robIt = nums[i] + maxRobbedAmount(nums,dp, i+2);
        int dontRob = maxRobbedAmount(nums,dp, i+1);

        int ans = max(robIt, dontRob);
        return dp[i] = ans;
    }

    int iterativeSolution(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n+5, -1);
        dp[n] = 0;
        dp[n+1] = 0;
        for(int i = n-1; i >= 0; i--){
            int robIt = nums[i] + dp[i+2];
            int dontRob = dp[i+1];

            int ans = max(robIt, dontRob);
            dp[i] = ans;
        }
        return dp[0];
    }
    int spaceOptimisation(vector<int> &nums){
        int n = nums.size();
        int prevRobbed = 0;
        int prev2Robbed = 0;
        for(int i = n-1; i >= 0; i--){
            int robIt = nums[i] + prev2Robbed;
            int dontRob = prevRobbed;

            int ans = max(robIt, dontRob);
            
            int current = ans;
            prev2Robbed = prevRobbed;
            prevRobbed = current;
        }
        return prevRobbed;
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1, -1);
        // int ans = maxRobbedAmount(nums, dp);
        // int ans = iterativeSolution(nums);
        int ans = spaceOptimisation(nums);
        return ans;
    }
};