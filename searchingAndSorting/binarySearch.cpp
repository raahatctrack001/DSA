class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end =nums.size()-1;

        //start == end is the case when one [5] and target is also 5
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;            
            else
                start = mid+1;
        }
        return -1;
    }
};