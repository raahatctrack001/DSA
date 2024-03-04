solution link: https://leetcode.com/problems/bag-of-tokens/solutions/4820126/thinking-process-recursion-memoization-dp-greedy-all-approaches-d
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(),tokens.end());
        int i =0,j=n-1;
        int score=0;
        int res=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                res=max(res,score);
                power-=tokens[i];
                i++;
            } else if(score>0){
                power+=tokens[j];
                score--;
                j--;   
            } else {
                i++;
            }
        }
        return res;
    }
};