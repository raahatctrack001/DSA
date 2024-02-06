class Solution {
    int firstOccurance(vector<int> &nums, int target){
        int firstTargetIndex = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                firstTargetIndex = mid;
                //to avoid infinite loop update end part as we don't need the right part: we want first occurance so its good to go for left part
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

            else
                start = mid+1;
        }
        return lastTargetIndex;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstTargetIndex = firstOccurance(nums, target);
        int lastTargetIndex = lastOccurance(nums, target);
        return {firstTargetIndex, lastTargetIndex};
    }
};