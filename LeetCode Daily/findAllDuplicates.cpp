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