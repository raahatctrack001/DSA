class Solution {
    void merge(vector<int> &nums, int start, int mid, int end) {
        vector<int> arr(end-start+1, 0);
        int i = start;
        int j = mid+1;
        int k = 0;
        while(i <= mid and j <= end)
            arr[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];

        while(i <= mid)
            arr[k++] = nums[i++];
        
        while(j <= end)
            arr[k++] = nums[j++];
        
        i = 0;
        for(; i < end-start+1; i++)
            nums[start+i] = arr[i];
    }

void mergeSort(vector<int> &nums, int start, int end) {
	if(start >= end)
        return;
    
    int mid = start+(end-start)/2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid+1, end);
    merge(nums, start, mid, end);
}
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};