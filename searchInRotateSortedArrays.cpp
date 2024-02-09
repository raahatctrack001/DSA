class Solution {
    int getPivoteIndex(vector<int> &nums){
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(nums[mid] >= nums[0])
                start = mid+1;
            else
                end = mid;
            //why not end = mid-1? dry run this function on 3 4 5 2 1 to get the answer
        }
        return start;
    }
    int binarySearch(vector<int> &nums, int target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivoteIndex = getPivoteIndex(nums);
        int start = 0;
        int end = 0;
        if(target >= nums[pivoteIndex] and target <= nums[nums.size()-1]){            
            start = pivoteIndex;
            end = nums.size()-1;
        }
        else{
            
            start = 0;
            end = pivoteIndex-1;
        }
        int targetIndex = binarySearch(nums, target, start, end);
        return targetIndex;
    }
};