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

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)
            return {};
        
        vector<string> ans;
       vector<string> patterns;
        for(int i = 0; i <= s.size()-10; i++)
            patterns.push_back(s.substr(i, 10));
        
        sort(patterns.begin(), patterns.end());
        for(auto &pattern: patterns)
            cout<<pattern<<endl;;

        int count = 1;
        for(int i = 1; i < patterns.size(); i++){
            if(patterns[i] == patterns[i-1]){
                count++;
            }
            else{
                if(count > 1)
                    ans.push_back(patterns[i-1]);
                count = 1;
            }
        }
        if(count > 1)
            ans.push_back(patterns.back());

        return ans;      
    }
};