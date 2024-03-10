class Solution {
public:
    vector<int> intersection(vector<int>& first, vector<int>& second) {
        int freq[1000];
        for(auto &num: first)
            freq[num]++;
        
        vector<int> ans;
        for(auto &num: second){
            if(freq[num] > 0){
                ans.push_back(num);
                freq[num] *= -1;
            }
        }
        return ans;
    }
};