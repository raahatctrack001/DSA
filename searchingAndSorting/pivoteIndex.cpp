class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) pre[i] = nums[i] + pre[i-1];
        for(int i = 0; i < n; i++){
            int lsum = 0;
            if(i > 0) lsum = pre[i-1];
            int rsum = pre[n-1] - pre[i];
            if(lsum == rsum) return i;
        }
        return -1;
    }
};

class Solution {
public:
/*value:            1 7 3 6 5 6
  index:            0 1 2 3 4 5 
  preSum:           1 8 11 17 22 28
  Rightsum at i= preSum[n-1] - preSum[i]
let say i = 3;
preSum[5]-preSum[3] = 28-11 = 17        
 */
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) pre[i] = nums[i] + pre[i-1];
        for(int i = 0; i < n; i++){
            int lsum = 0;
            if(i > 0) lsum = pre[i-1];
            int rsum = pre[n-1] - pre[i];
            if(lsum == rsum) return i;
        }
        return -1;
    }
};