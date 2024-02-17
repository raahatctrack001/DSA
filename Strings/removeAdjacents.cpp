class Solution {
public:
    string removeDuplicates(string s) {
        vector<int> str;
        for(auto &ch : s){
            if(!str.empty() and str.back() == ch)
                str.pop_back();
            else
                str.push_back(ch);
        }

        string ans = "";
        for(auto &ch : str)
            ans += ch;
        return ans;
    }
};