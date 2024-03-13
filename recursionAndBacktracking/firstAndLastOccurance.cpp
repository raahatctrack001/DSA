class Solution {

    int firstOccuranceRecursion(vector<int> &nums, int target, int i = 0){
        if(i >= nums.size())
            return -1;

        if(nums[i] == target)
            return i;

        return firstOccuranceRecursion(nums, target, i+1);
    }
    int lastOccuranceRecursion(vector<int> &nums, int target, int i){
        if(i < 0)
            return -1;

        if(nums[i] == target)
            return i;

        return lastOccuranceRecursion(nums, target, i-1);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstTargetIndex = firstOccuranceRecursion(nums, target);
        int lastTargetIndex = lastOccuranceRecursion(nums, target, nums.size()-1);
        return {firstTargetIndex, lastTargetIndex};
    }
};