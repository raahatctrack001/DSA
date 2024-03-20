class Solution {
    int getleastNumberOfPerfectSquares(int n, vector<int> &dp){
        if(n <= 0)
            return 0;

        if(dp[n] != INT_MAX)
            return dp[n];

        int currentNumber = 1;
        int searchUntil = sqrt(n);

        int minPerfectSquares = INT_MAX;

        while(currentNumber <= searchUntil){
            int perfectSquare = pow(currentNumber, 2);
            int numberOfPerfectSquaresTillNow = 1 + getleastNumberOfPerfectSquares(n-perfectSquare, dp);
            minPerfectSquares = min(minPerfectSquares, numberOfPerfectSquaresTillNow);
            currentNumber++;
        }

        return dp[n] = minPerfectSquares;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        int leastNumberOfPerfectSquares = getleastNumberOfPerfectSquares(n, dp);
        return leastNumberOfPerfectSquares;   
    }
};
