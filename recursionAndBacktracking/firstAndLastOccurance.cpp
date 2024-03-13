class Solution {
    int firstOccurance(vector<int> &nums, int target){
        int firstTargetIndex = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                firstTargetIndex = mid;
                end = mid-1;
            }
            else if(nums[mid] > target)
                end = mid-1;
            else 
                start = mid+1;
        }
        return firstTargetIndex;
    }

    int lastOccurance(vector<int> &nums, int target){
        int lastTargetIndex = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                lastTargetIndex = mid;
                start = mid+1;
            }
            else if(nums[mid]  > target)
                end = mid-1;

            else start = mid+1;
        }
        return lastTargetIndex;
    }
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