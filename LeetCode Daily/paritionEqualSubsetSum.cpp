class Solution {
public:
    bool checkIfPossible(vector<int> &nums, vector<vector<int>> &dp, int target, int i = 0){
        if(i >= nums.size()){
            if(target == 0)
                return true;
            return false;
        }

        if(dp[target][i] != -1)
            return dp[target][i];

        bool include = false;
        if(target-nums[i] >= 0) 
            include = checkIfPossible(nums, dp, target-nums[i], i+1);

        bool exclude = checkIfPossible(nums, dp, target, i+1);
        return dp[target][i] = (include or exclude);
    }
    bool iterativeSolution(vector<int> &nums, int target){
        vector<vector<int>> dp(target+1, vector<int> (nums.size()+1, 0));
        //fill up the base cases here 
        for(int i = 0; i < nums.size(); i++)
            dp[0][i] = 1;
        
        for(int t = 1; t <= target; t++){
            for(int i = nums.size()-1; i >= 0; i--){
                bool include = false;
                if(t-nums[i] >= 0) 
                    include = dp[t-nums[i]][i+1];

                bool exclude = dp[t][i+1];
                dp[t][i] = (include or exclude);
            }
        }
        return dp[target][0];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
            return false;
        int target = sum/2;
        // vector<vector<int>> dp(target+1, vector<int> (nums.size()+1, -1)); // always insert value in dp which can't come as an answer!
        // return checkIfPossible(nums, dp, target, 0);
        return iterativeSolution(nums, target);
    }
};