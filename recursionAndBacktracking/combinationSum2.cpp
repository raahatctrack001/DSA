class Solution {
public:
    void getAllCombinations(vector<int> &candidates, vector<vector<int>> &allCombinations, vector<int> &singleCombination, int target, int i = 0){
        if(i >= candidates.size()){
            if(target == 0)
                allCombinations.push_back(singleCombination);
            return;
        }
    

        if(i >= candidates.size() or target < 0)
            return;

        singleCombination.push_back(candidates[i]);
        getAllCombinations(candidates, allCombinations, singleCombination, target-candidates[i], i+1);
        singleCombination.pop_back();

        while(i+1 < candidates.size() and candidates[i] == candidates[i+1])
            i++;

        getAllCombinations(candidates, allCombinations, singleCombination, target, i+1);
    }      
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> allCombinations;
        vector<int> singleCombination;

        getAllCombinations(candidates, allCombinations, singleCombination, target);

        return allCombinations;
    }
};