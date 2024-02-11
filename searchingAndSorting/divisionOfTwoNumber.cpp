class Solution {
public:
    long divide(long dividend, long divisor) {
        long start = 1, end = abs(dividend), mid = 0, ans = 0;
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
          if (divisor == 0 || (dividend == INT_MIN && divisor == 1)) 
            return INT_MIN;
        
        while(start <= end){
            mid = start + (end - start)/2;
            if(abs(divisor*mid)<=abs(dividend))
            {
                ans=mid;
                start = mid+1;
            }
            else 
                end=mid-1;
            
        }
        return divisor * dividend < 0 ? -1 * ans : ans;
    }
};