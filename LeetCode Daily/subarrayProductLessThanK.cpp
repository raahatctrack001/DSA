class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;

        long long product = 1;
        int count = 0;
        int start = 0;
        //increase window size
        for(int end = 0; end < nums.size(); end++){
            product *= nums[end];

            //reduce window size if applicable
            while(product >= k and start < nums.size())
                product /= nums[start++];
                
            //count possible subarray whose prouduct < k
            if(product < k)
                count += end-start+1;
        }
        return count;
    }
};