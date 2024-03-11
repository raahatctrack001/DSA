class Solution {
public:
    //count of five = n/5 + n/25 + n/125 + n/625 + ...
    int getCountOfFive(int n, int count, int factor){
        if(n/factor == 0)
            return count;
            
        return getCountOfFive(n, count+n/factor, factor*5);
    }
    int trailingZeroes(int n){
        int ans = getCountOfFive(n, 0, 5);
        return ans;
    }
};