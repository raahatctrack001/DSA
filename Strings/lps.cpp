class Solution {
public:
    string longestPalindrome(string s) {
        auto expandFromCenter = [&](int left, int right){
           while(left >= 0 and right < s.size() and s[left] == s[right]){
              left--;
              right++;
           }
           return s.substr(left+1, right-left-1);
        };

        //confusion about the type of variable
        // cout<<typeid(expandFromCenter).name(); 

        string lps = s.substr(0,1);
        for(int i = 0; i < s.size(); i++){
            string handleOddLen = expandFromCenter(i, i);
            string getFromEvenLen = expandFromCenter(i, i+1);
            if(handleOddLen.size() >lps.size())
                lps = handleOddLen;
            
            if(getFromEvenLen.size() > lps.size())
                lps = getFromEvenLen;
        }
        return lps;
    }
};