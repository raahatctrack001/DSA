class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(!strs.size())
            return {{}};

        if(strs.size() == 1)
            return {{strs[0]}};

        unordered_map<string, vector<string> > anagramCollection;
        for(auto &str : strs){
            string word = str;
            sort(word.begin(), word.end());
            anagramCollection[word].push_back(str);
        }

        vector<vector<string>> anagramCollected;
        for(auto &it : anagramCollection){
            anagramCollected.push_back(it.second);
        }

        return anagramCollected;
    }
};