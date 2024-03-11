class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), c=0;
        if(n == 0) return "";
        if(n == 1) return strs[0];
        sort(strs.begin(), strs.end());
        string first = strs[0], second = strs[n-1];
        int sz = min(first.size(), second.size());
        for(int i = 0; i < sz; i++){
            if(first[i] == second[i]) c++;
            else break;
        }
        return c == 0 ? "" : first.substr(0, c);

        
    }
};