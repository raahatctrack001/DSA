class Solution {
public:
    int getLongestIdeal(string &s, int k, vector<vector<int>> &dp, int prev = 0, int currIndex = 0){
        if(currIndex >= s.size())
            return 0;

        if(dp[currIndex][prev] != -1)
            return dp[currIndex][prev];

        int include = 0;
        if(prev == 0 or abs(s[currIndex]-prev) <= k){
            include = 1+getLongestIdeal(s, k, dp, s[currIndex], currIndex+1);
        }

        int exclude = getLongestIdeal(s, k, dp, prev, currIndex+1);
        return dp[currIndex][prev] = max(include, exclude);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size()+3, vector<int> (125, -1));
        return getLongestIdeal(s, k, dp);
    }
};