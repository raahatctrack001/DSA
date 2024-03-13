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


//AP Solution .. i.e. x*x = sum
class Solution {
public:
//ap solution: sum(1, n) = sum(1, x) + sum(x, n);
//sum(1, x) = sum(1, n)-sum(x, n);
//sum = n*(n+1)/2;
//=> x*(x+1)/2 = n*(n+1)/2 - (x*(x-1))/2;
//x*x = n*(n+1)/2;

//based on the same logic
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int pivote = sqrt(sum);

        return pow(pivote, 2) == sum ? pivote : -1;
    }
};