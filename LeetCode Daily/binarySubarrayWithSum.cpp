class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int subarrayCount = 0;
        for(int i = 0; i < nums.size(); i++){
            int currentSum = nums[i];
            if(currentSum == goal)
                subarrayCount++;
            for(int j = i+1; j < nums.size(); j++){
                currentSum += nums[j];
                if(currentSum == goal)
                    subarrayCount++;
                
                if(currentSum > goal)
                    break;
            }
        }
        return subarrayCount;
    }
};