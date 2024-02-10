class Solution {
    int expandAndCheck(string &s, int i, int j){
        int count = 0;
        while((i >= 0 and j < s.size()) and s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int palindromicSubstringCount = 0;

        for(int i = 0; i < s.size(); i++){
            palindromicSubstringCount += expandAndCheck(s, i, i); //handles odd length palindromic substring 
            palindromicSubstringCount += expandAndCheck(s, i, i+1);  //handles even length palindromic substring
        }
        return palindromicSubstringCount;
    }
};