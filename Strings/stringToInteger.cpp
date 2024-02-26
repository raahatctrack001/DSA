class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        //skip the whitespaces
        while(i < s.size() and s[i] == ' ')
            i++;
        //mark as true if either sign appears
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';

        //if either is true increment i by 1
        //taking advantage of && operator, it will check next condition
        //only if  first one is true 
        positive && i++;
        negative && i++;

        double ans = 0;
        //converting digit char into digit
        while(i < s.size() and (s[i] >= '0' and s[i] <= '9')){
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        //negative is encountered
        ans = negative ? -1*ans : ans;

        //handling edge cases when ans has cross its boundary! hahaha
        ans = ans > INT_MAX ? INT_MAX : ans;
        ans = ans < INT_MIN ? INT_MIN : ans;
        return ans;
    }
};