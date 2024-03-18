class Solution {
    vector<vector<int>> combinations;
    void getCombination(vector<int> &candidates, vector<int> &temp, int target, int i = 0){
        if(i >= candidates.size()){
            if(target == 0)
                combinations.push_back(temp);
            return;
        }

        if(target-candidates[i] >= 0){
            temp.push_back(candidates[i]);
            getCombination(candidates, temp, target-candidates[i], i);
            temp.pop_back();

        }
        getCombination(candidates, temp, target, i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        getCombination(candidates, temp, target, 0);
        return combinations;
    }
};