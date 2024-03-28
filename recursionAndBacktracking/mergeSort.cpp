class Solution {
public:
    void merge(vector<int> &nums, int start, int mid, int end){
        vector<int> temp(end-start+1);

        int i = start;
        int j = mid+1;
        int k = 0;
        while(i <= mid and j <= end){
            if(nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while(i <= mid)
            temp[k++] = nums[i++];

        
        while(j <= end)
            temp[k++] = nums[j++];

        k = 0;
        for(int i = start; i <= end; i++)
            nums[i] = temp[k++];
    }
    void mergeSort(vector<int> &nums, int start, int end){
        if(start >= end)
            return;
        int mid = (start+end) >> 1;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);        
    }
    vector<int> sortArray(vector<int>& nums) {
  
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};