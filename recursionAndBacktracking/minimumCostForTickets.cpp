class Solution {
    int getMinCost(vector<int> &days, vector<int> &costs, vector<int> &dp, int i = 0){
        if(i >= days.size())
            return 0;

        if(dp[i] != INT_MAX)
            return dp[i];

        int oneDayCost = costs[0] + getMinCost(days, costs, dp, i+1);

        int sevenDayPassExpiry = days[i]+6;
        int j = i;
        while(j < days.size() and days[j] <= sevenDayPassExpiry){
            j++;
        }

        int sevenDayCost = costs[1] + getMinCost(days, costs, dp, j);

        int thirtyDaysPassExpiry = days[i] + 29;
        j = i;
        while(j < days.size() and days[j] <= thirtyDaysPassExpiry){
            j++;
        }
        int thirtyDayCost = costs[2] + getMinCost(days, costs, dp, j);

        return dp[i] = min(oneDayCost, min(sevenDayCost, thirtyDayCost));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        int minCost = getMinCost(days, costs, dp);
        return minCost;   
    }
};