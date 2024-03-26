class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 1; i <= nums.size()+1; i++){
            bool flag = false;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == i)
                    flag = true;
            }
            if(!flag)
                return i;
        }
        return nums.size()+1;
    }
};