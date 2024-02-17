class Solution {
    bool isStringPalindrome(string &str){
        for(int i = 0, j = str.size()-1; i < j; i++, j--){
            if(str[i] != str[j])
                return false;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string filteredString = "";
        for(auto &ch : s){
            if(isalnum(ch)){
                if(isupper(ch))
                    ch += 32;
                filteredString += ch;
            }
                
        }

        bool ans = isStringPalindrome(filteredString);
        return ans;
    }
};