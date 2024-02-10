int searchInNearySortedArray(vector<int> &nums, int target){
    int start = 0;
    int end = nums.size()-1;

    while(start <= end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target)
            return mid;
        if((mid-1 >= start) and (nums[mid-1] == target))
            return mid-1;
        if((mid+1 <= e) and (nums[mid+1] == target))
            return mid+1;
        
        if(nums[mid] > target)
            end = mid-2; //mid-1 is already checked so no need to check once more
        
        else
            start = mid+2; //similarly mid+1 is also checked
        
    }
    return -1;
}