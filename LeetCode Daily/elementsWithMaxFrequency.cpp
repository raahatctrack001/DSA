class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto &num: nums)
            freq[num]++;

        vector<int> count;
        for(auto &it : freq)
            count.push_back(it.second);

        sort(count.begin(), count.end(), [&](int a, int b)->bool{
            return a > b;
        });        

        int ans = count[0];
        for(int i = 1; i < count.size(); i++){
            if(count[i] == count[i-1])
                ans += count[i];
            else
                break;
        }

        return ans;
    }
};