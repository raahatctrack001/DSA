class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int frequency = count(s.begin(), s.end(), '1');
        int n = s.size();
       
       string res(n, '0');
       if(frequency >= 1)
        res[n-1] = '1';
       
       frequency--;
       
       for(int i = 0; i < frequency; i++)
        res[i] = '1';
       return res;

    }
};