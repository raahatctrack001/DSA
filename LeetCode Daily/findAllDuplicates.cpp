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

//xor solution same values => zero
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

//O(n) and O(1) solution:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i])-1;

            if(nums[index] < 0)
                ans.push_back(index+1);
            
            nums[index] = -1*nums[index];
        }
        return ans;
    }
};