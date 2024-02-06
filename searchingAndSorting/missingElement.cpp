class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int vectorSum = accumulate(nums.begin(), nums.end(), 0);
        int sumUptoN = n*(n+1)/2;
        return sumUptoN - vectorSum;

        // sort(nums.begin(),nums.end());
        // for(int i = 0; i < nums.size(); i++)
        //     if(i != nums[i])
        //         return i;

        // return nums.size();
        
    }
};