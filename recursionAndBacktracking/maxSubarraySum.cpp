class Solution {
    int maxValue(vector<int> &nums, int currentSum, int maxSum, int i = 0){
        if(i >= nums.size())
            return maxSum;

        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
        currentSum  = currentSum < 0 ? 0 : currentSum;

        return maxValue(nums, currentSum, maxSum, i+1);
    }
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = nums[0]; //to handle nums = [-1] : maxSum = nums[0] and not maxSum = 0;

        return maxValue(nums, currentSum, maxSum);
    }
};