class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        bool minFound = 0;
        bool maxFound = 0;

        int minStartIndex = 0;
        int maxStartIndex = 0;
        
        int startOfSubarray = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK or nums[i] > maxK){
                minFound = 0;
                maxFound = 0;
                startOfSubarray = i+1;
            }
            else{
                if(nums[i] == minK){
                    minFound = 1;
                    minStartIndex = i;
                }
                if(nums[i] == maxK){
                    maxFound = 1;
                    maxStartIndex = i;
                }
            }

            if(minFound and maxFound)
                ans += ((min(minStartIndex, maxStartIndex) - startOfSubarray + 1));
        }
        return ans;
    }
};