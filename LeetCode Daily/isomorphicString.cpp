class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> tToS, sToT;
        int len = s.size();
        for(int i = 0; i < len; i++){
            char sChar = s[i];
            char tChar = t[i];
            if(sToT.find(s[i]) != sToT.end() and sToT[sChar] != tChar)
                return false;

            if(tToS.find(t[i]) != tToS.end() and tToS[tChar] != sChar)
                return false;

            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        }
        return true;
    }
};


// typdef for(i,a,b) = for(int i = a; i <)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        for(int i = 0; i < s.size(); i++){
            //if mapping of s[i] already exists and now mapping of s[i] doesn't matches t[i] hence return false!
            if(mp.find(s[i]) != mp.end() and mp[s[i]] != t[i])
                return false;
            
            mp[s[i]] = t[i];
        }
        mp.clear();

        for(int i = 0; i < s.size(); i++){
            if(mp.find(t[i]) != mp.end() and mp[t[i]] != s[i])
                return false;
            
            mp[t[i]] = s[i];
        }
        return true;
    }
};