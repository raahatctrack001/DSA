//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int getMaxValue(int weight[], int value[], int n, vector<vector<int>> &dp, int capacity, int i){
        if(i >= n)
            return 0;
            
        if(capacity < 0)
            return 0;
            
        if(dp[capacity][i] != INT_MIN)
            return dp[capacity][i];
            
        int include = INT_MIN;
        if(capacity-weight[i] >= 0)
            include = value[i] + getMaxValue(weight, value, n, dp, capacity-weight[i], i+1);
        int exclude = getMaxValue(weight, value, n, dp, capacity, i+1);
        
        return dp[capacity][i] = max(include, exclude);
    }
    
    int iterativeSolution(int weight[], int value[], int n, int capacity){
        vector<vector<int>> dp(capacity+1, vector<int> (n+1, 0));
        
        for(int load = 0; load <= capacity; load++){
            for(int i = n-1; i >= 0; i--){
                int include = INT_MIN;
                if(load-weight[i] >= 0)
                    include = value[i] +  dp[load-weight[i]][i+1];
                int exclude = dp[load][i+1];
            
                dp[load][i] = max(include, exclude);
            }
        }
        return dp[capacity][0];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(W+1, vector<int> (n+1, INT_MIN));
    //   return getMaxValue(wt, val, n, dp, W, 0);
    return iterativeSolution(wt, val, n, W);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends