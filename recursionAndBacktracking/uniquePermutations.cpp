class Solution {
    private:
    void solve(vector<vector<int>> &res, vector<int> &nums, int i){
        if(i>=nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_map<int, bool> mp;
        for(int j = i; j < nums.size(); j++){
            if(mp.find(nums[j]) != mp.end())
                continue;
            mp[nums[j]] = true;
            swap(nums[i], nums[j]);
            solve(res, nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res, nums, 0);
        // sort(res.begin(), res.end());
        // res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};