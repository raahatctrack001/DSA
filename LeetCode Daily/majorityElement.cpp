//if a number appears more than n/2 time means sorting them will keep the majority element at n/2th index;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
// storing the frequency of element in map and if frequency exceeds n/2, that's the majority element;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
unordered_map <int, int> m;
        for(auto x: nums){
            m[x]++;
            if(m[x]>n/2) return x;
        }
        return -1;
    }
};