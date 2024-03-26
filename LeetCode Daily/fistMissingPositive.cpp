class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 1; i <= nums.size()+1; i++){
            bool flag = false;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] == i)
                    flag = true;
            }
            if(!flag)
                return i;
        }
        return nums.size()+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto &num: nums)
            mp[num] = true;

        for(int i = 1; i <= nums.size(); i++)
            if(mp.find(i) == mp.end())
                return i;

        return nums.size()+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};