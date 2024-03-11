class Solution {
public:
    string customSortString(string order, string s) {
        string copy  = s;
        
        //sort the string with the technique in which first character i.e. char a come before char b in string order;
        sort(copy.begin(), copy.end(), [&](char &a, char &b)->bool{
            return order.find(a) < order.find(b);
        });

        return copy;
    }
};