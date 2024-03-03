class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string window = "";
        for(int i = 0; i < 10; i++)
            window.push_back(s[i]);
        
        unordered_map<string, int> frequency;
        frequency[window]++;
        for(int i = 10; i < s.size(); i++){
            window.push_back(s[i]);
            window.erase(0, 1);
            frequency[window]++;
        }      
        vector<string> ans;
        for(auto &it : frequency)
            if(it.second > 1)
                ans.push_back(it.first);

        return ans;
    }
};