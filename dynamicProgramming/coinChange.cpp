class Solution {
public:
    int coinsCollected(vector<int> &coins, vector<int> &dp, int amount){
        if(amount < 0) 
            return INT_MAX;
        
        if(amount == 0)
            return 0;

        if(dp[amount] != INT_MIN) // make sure base cases return value and values stored in dp isn't same!
            return dp[amount];


        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int ans = coinsCollected(coins, dp, amount-coins[i]);
            if(ans != INT_MAX){
                mini = min(mini, 1+ans);
            }
        }

        return dp[amount] = mini;
    }

    int tabulation(vector<int> &coins, int amount){
        vector<int> dp(amount+1, -1);
        dp[0] = 0;

        for(int target = 1; target <= amount; target++){
            // int coinsCount = INT_MAX;
            int mini = INT_MAX;
            for(int i = 0; i < coins.size(); i++){
                if(target-coins[i] >= 0){
                    int ans = dp[target-coins[i]];
                    if(ans != INT_MAX){
                        mini = min(mini, 1+ans);
                    }
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1, INT_MIN);
        // int ans = coinsCollected(coins, dp, amount);
        int ans = tabulation(coins, amount);
        if(ans == INT_MAX)
            return -1;

        return ans;
    }   
};