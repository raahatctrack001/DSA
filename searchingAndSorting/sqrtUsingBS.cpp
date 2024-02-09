class Solution {
public:
    long long int mySqrt(int x) {
        if(x == 1)
            return 1;
        int start = 0;
        int end = x;
        long long int ans = 0;
        while(start < end){
            long long int mid = start + (end-start)/2;
            long long int squaredValue = mid*mid;
            if(squaredValue <= x)
                {
                    ans = mid;
                    start = mid+1;
                }
            else
                end = mid;
        }
        return ans;
    }
};
//decimal precision
// int precision = 5;
// double finalAns = ans;
// for(int i = 0; i < precision; i++){
//     for(int j = finalAns; j*j < n; j+= steps){
//         finalAns = j;
//     }
//     step /= 10;
// }
// return finalAns;