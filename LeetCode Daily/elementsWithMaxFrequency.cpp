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

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sortedFrequencies;
        int frequency = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                frequency++;
            else{
                sortedFrequencies.push_back(frequency);
                frequency = 1;
            }
        }
        sortedFrequencies.push_back(frequency);
        sort(sortedFrequencies.begin(), sortedFrequencies.end(), [&](int &a, int &b)->bool{
            return a > b;
        });

        int maxFrequency = sortedFrequencies[0];
        for(int i = 1; i < sortedFrequencies.size(); i++){
            if(sortedFrequencies[i] == sortedFrequencies[i-1])
                maxFrequency += sortedFrequencies[i];
            else
                break;
        }
        return maxFrequency;
    }
};