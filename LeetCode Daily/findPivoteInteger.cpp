class Solution {
public:
    int pivotInteger(int n) {
        int preSum = n*(n+1)/2;
        int currentSum = 0;
        for(int i = 1; i <= n; i++){
            currentSum += i;
            int rightSum = preSum-currentSum+i;
            if(currentSum == rightSum)
                return i;
        }

        return -1;
        //
    }
};