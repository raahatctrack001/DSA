class Solution {
public:
    int getSteps(string &ring, string &key, vector<vector<int>> &dp, int r = 0, int keyIndex = 0){
        if(keyIndex >= key.size())
            return 0;

        if(dp[r][keyIndex] != -1)
            return dp[r][keyIndex];

        int ans = 1e9;
        for(int i = 0; i < ring.size(); i++){
            if(ring[i] == key[keyIndex]){
                int distance = min(abs(i-r), (int)ring.size() - abs(i-r)); // the char we've found here, is it nearest from start or end, start is relative here... start means current word at 12:00
                ans = min(ans, 1+distance + getSteps(ring, key, dp, i, keyIndex+1));
            }
        }
        return dp[r][keyIndex] = ans;
        
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(ring.size()+1, vector<int> (key.size()+1, -1));
        return getSteps(ring, key, dp, 0, 0);
    }
};