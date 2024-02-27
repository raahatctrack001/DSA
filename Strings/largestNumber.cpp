class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> strs;
        for(auto &num : nums){
            string temp = to_string(num);
            strs.push_back(temp);
        }
        //most important agar ye nhi kia to sb bekar
        sort(strs.begin(), strs.end(), [](auto &first, auto &second)->bool{     
            //[3,30,34,5,9]
            // 3+30 > 30 + 3 in strings
            //9+5 > 5 + 9
            // 95+30 < 95 + 34
            //it will sort string something like this 9 5 34 3 30
            return first+second > second+first;
        });

        for(auto &str : strs)
            res += str;

        // return res;
        //handling this case : [0,0]
        return res[0] == '0' ? "0" : res;
        
        
    }
};