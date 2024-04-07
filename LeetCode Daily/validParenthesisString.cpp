class Solution {
public:
    bool checkValid(string &s, vector<vector<int>> &dp, int i=0, int open=0){
        if(i == s.size())
            return open == 0;
        if(dp[i][open] != -1)
            return dp[i][open];

        bool ans = false;
        if(s[i] == '*'){
            ans |= checkValid(s, dp, i+1, open+1);
            if(open)
                ans |= checkValid(s, dp, i+1, open-1);
            ans |= checkValid(s, dp, i+1, open);
        }
        else{
            if(s[i] == '(')
                ans |= checkValid(s, dp, i+1, open+1);
            else
                if(open)
                    ans |= checkValid(s, dp, i+1, open-1);
        }
        return dp[i][open] = ans;
    }

    bool iterativeDP(string &s){
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, 0));
        dp[s.size()][0] = 1;
        for(int i = s.size()-1; i >= 0; i--){
            for(int open = s.size()-1; open >= 0; open--){
                bool ans = false;
                if(s[i] == '*'){
                    ans |= dp[i+1][open+1];
                    if(open)
                        ans |= dp[i+1][open-1];
                    ans |= dp[i+1][open];
                }
                else{
                    if(s[i] == '(')
                        ans |= dp[i+1][open+1];
                    else
                        if(open)
                            ans |= dp[i+1][open-1];
                }
                dp[i][open] = ans;
            }            
        }
        return dp[0][0];
    }   

    bool spaceOptimisation(string &s){
        vector<int> next(s.size()+1, 0);
        vector<int> curr(s.size()+1, 0);
        next[0] = 1;
        
        for(int i = s.size()-1; i >= 0; i--){
            for(int open = s.size()-1; open >= 0; open--){
                bool ans = false;
                if(s[i] == '*'){
                    ans |= next[open+1];
                    if(open)
                        ans |= next[open-1];
                    ans |= next[open];
                }
                else{
                    if(s[i] == '(')
                        ans |= next[open+1];
                    else
                        if(open)
                            ans |= next[open-1];
                }
                curr[open] = ans; 
            }            
            next = curr;
        }
        return curr[0];
    }

    bool furtherSpaceOptimisation(string &s){
        int next = 0;
        int curr = 0;
        int prev = 0;
        next = 1;
        int currOpen;
        
        for(int i = s.size()-1; i >= 0; i--){
            for(int open = s.size()-1; open >= 0; open--){
                bool ans = false;
                if(s[i] == '*'){
                    ans |= next];
                    if(open)
                        ans |= prev;
                    ans |= curr;
                }
                else{
                    if(s[i] == '(')
                        ans |= next;
                    else
                        if(open)
                            ans |= prev;
                }
                currOpen = ans; 
            }           
            curr = prev;
            next = curr; 
            next = curr;
        }
        return curr[0];

    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size()+1, -1));
        return spaceOptimisation(s);

    }
};