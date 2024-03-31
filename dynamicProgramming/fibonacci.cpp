class Solution {
public:
    int fibonacci(int n){
        if(n == 0 or n == 1)
            return n;

        return fibonacci(n-1) + fibonacci(n-2);
    }
    int fibonacciDP(vector<int> &dp, int n){
        if(n == 0 or n == 1)
            return n;

        if(dp[n] != -1)
            return dp[n];

        int ans = fibonacci(n-1)+fibonacci(n-2);
        dp[n] = ans;

        return dp[n];

    }
    int iterativeDP(int n){
        if(n == 0 or n == 1)
            return n;
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = 1; // for n == 0, size of dp is 1 i.e. only index avail is 0 dp[0] = 0 and dp[1] isn't applicable

        for(int i = 2; i <= n; i++){
            
            dp[i] = dp[i-1]+dp[i-2];

        }
        return dp[n];

    }
    int spaceOptimisation(int n){
        if(n == 0 or n == 1)
            return n;

        int prev = 1;
        int penultimate = 0;
        
        for(int i =2; i <= n; i++){
            int current = prev + penultimate;
            penultimate = prev;
            prev = current;
        }
        return prev;
    }
    int fib(int n) {
        // return fibonacci(n);
        // vector<int> dp(n+1, -1);
        // return fibonacciDP(dp, n);
        // return iterativeDP(n);
        return spaceOptimisation(n);
    }
};