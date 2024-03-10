//with map
class Solution {
public:
    vector<int> intersection(vector<int>& first, vector<int>& second) {
        unordered_map<int, int> freq;
        for(auto &num: first)
            freq[num]++;

        vector<int> ans;
        for(auto &num : second){
            if(freq.find(num) != freq.end() and freq[num] > 0){
                ans.push_back(num);
                freq[num] *= -1;
            }
        }
        return ans;
    }
};