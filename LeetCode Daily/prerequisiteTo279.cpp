class Solution {
    int targetSum(vector<int> &perfectSquares, int target){
        if(target == 0)
            return 0;
        
        if(target < 0)
            return INT_MAX;
        int minPerfectSquares = INT_MAX;
        for(int i = 0; i < perfectSquares.size(); i++){
            int ans = targetSum(perfectSquares, target-perfectSquares[i]);
            if(ans != INT_MAX)
                minPerfectSquares = min(minPerfectSquares, ans+1);
        }
        return minPerfectSquares;
    }
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        
        int i = 1;
        while(i*i <= n){
            cout<<i*i<<endl;
            perfectSquares.push_back(i*i);
            i++;
        }
        int minPerfectSquare = targetSum(perfectSquares, n);
        return minPerfectSquare;
    }
};