class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //consideri all the sides as valid hence sum it
        long long prevSum = 0;
        for(const int &num : nums)
            prevSum += num;

        int n = nums.size();
        for(int i = n-1; i >=2; i--){
            //lets invalidate ith side and check if we can include it or not
            prevSum -= nums[i];
            //as elements are sorted and hence first time this condition satisfies mean all other will also agree
            if(prevSum > nums[i])
                return prevSum + nums[i];
        }
        return -1;
    }
};

