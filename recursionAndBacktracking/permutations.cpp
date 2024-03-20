class Solution {
public:
    vector<vector<int>> ans;
    void permutations(vector<int> &nums, int i = 0){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            permutations(nums, i+1);

            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(nums);

        return ans;
    }
};