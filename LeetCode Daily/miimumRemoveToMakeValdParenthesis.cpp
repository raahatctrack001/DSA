class Solution {
public:
// leetcode daily
    string minRemoveToMakeValid(string s) {
        int openParenthesis = 0;
        string filteredForClose = "";

        for(auto &ch : s){
            if(ch == '(')
                openParenthesis++;
            else if(ch == ')'){
                if(openParenthesis == 0) // including this close bracket will cause imbalance as there's no prior open parenthesis to balance it
                    continue;  
                openParenthesis--;   //if can take it now as prior open parenthesisis is present to balance it           
            }
            filteredForClose += ch;
        }   
        if(openParenthesis == 0) //filtered for close and open == 0 => string is filtered and balanced
            return filteredForClose;

        //openParenthesis != 0 => close imbalance is there 
        int len = filteredForClose.size();
        string filteredForOpen = "";
        int closeParenthesis = 0;
        for(int i = len-1; i >= 0; i--){
            char ch = filteredForClose[i];
            if(ch == ')')
                closeParenthesis++;
            else if(ch == '('){
                if(closeParenthesis == 0)
                    continue;
                closeParenthesis--;
            }
            filteredForOpen += ch;                
        }

        reverse(filteredForOpen.begin(), filteredForOpen.end());
        return filteredForOpen;
    }
};