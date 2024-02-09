//TLE at 24/49

class Solution {
public:
    vector<int> answer;
    vector<vector<int>> divisibleVectors;
    int maxSize = INT_MIN;
    bool isDivisible(vector<int> &nums){
        for(int i = 1; i < nums.size(); i++){
            int first = nums[i-1];
            int second = nums[i];
          
            if((first % second == 0) or (second % first == 0))
                continue;
            else
                return false;
        }
        return true;
    }
    void getSubset(vector<int> &nums, vector<int> temp, int i = 0){
        //handle the base case;
        if(i == nums.size()){
           if(isDivisible(temp)){
               divisibleVectors.push_back(temp);
           }
           return;
        }

        temp.push_back(nums[i]);
        getSubset(nums, temp, i+1);
        temp.pop_back();

        getSubset(nums, temp, i+1);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        getSubset(nums, temp, 0);
        
        sort(divisibleVectors.begin(), divisibleVectors.end(), [](const auto &first, const auto &second){
            return first.size() > second.size();
        });

        
        return divisibleVectors[0];
        
        
    }
};

//TLE at 47/49
// On the same pattern of Longest Increasing Subsequences
class Solution {
    vector<int> answer;
    void getDivisibleSubset(vector<int> &nums, vector<int> &temp, int prev = INT_MIN, int i = 0){
        if(i >= nums.size()){
            if(temp.size() > answer.size())
                answer = temp;
            return;
        }

        if(nums[i] % prev == 0){
            temp.push_back(nums[i]);
            getDivisibleSubset(nums, temp, nums[i], i+1);
            temp.pop_back();            
        }

        getDivisibleSubset(nums, temp, prev, i+1);     

    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        getDivisibleSubset(nums, temp, 1, 0);
        return answer;
    }
};

//dp optimised code
class Solution {
    vector<int> answer;
    void getDivisibleSubset(vector<int> &nums, vector<int> &temp,vector<int> &dp, int prev, int i = 0){
        if(i >= nums.size()){
            if(temp.size() > answer.size())
                answer = temp;
            return;
        }

        if((int)temp.size() > dp[i] and nums[i] % prev == 0){
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            getDivisibleSubset(nums, temp, dp, nums[i], i+1);
            temp.pop_back();            
        }

        getDivisibleSubset(nums, temp, dp, prev, i+1);     

    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<int> dp(nums.size()+1, -1);
        getDivisibleSubset(nums, temp, dp, 1, 0);
        return answer;
    }
};