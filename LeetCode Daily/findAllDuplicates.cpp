class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map <int, int> m;
        vector<int> v;
        for(auto x: nums){
            m[x]++;
            if(m[x]>1) v.push_back(x);
        }
        return v;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(!(prev ^ nums[i]))
                ans.push_back(nums[i]);
            else
                prev = nums[i];
        }
        return ans;
    }
};