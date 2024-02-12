class Solution {
    bool isPossibleSolution(vector<int> &nums, int mid, int k){
        int subArraySum = 0;
        int noOfSplits = 1;
        for(int i = 0; i < nums.size(); i++){
            if(subArraySum + nums[i] <= mid)
                subArraySum += nums[i];
            else{
                noOfSplits++;
                if(noOfSplits > k or nums[i] > mid)
                    return false;
                subArraySum = nums[i];
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossibleSolution(nums, mid, k)){
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
        
    }
};