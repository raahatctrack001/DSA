class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> orderMap;
        for(int i = 0; i < order.size(); i++)
            orderMap[order[i]] = i;

        vector<pair<int, char> > sortedOrder;
        for(auto &it : orderMap)
            sortedOrder.push_back({it.second, it.first});

        sort(sortedOrder.begin(), sortedOrder.end());
        unordered_map<char, int> mappedChar;
        string res = "";
        for(auto &getOrder : sortedOrder){
            char orderChar = getOrder.second;
            for(auto &ch : s){
                if(orderChar == ch){
                    mappedChar[ch] = 1;
                    res += ch;
                }
            }
        }
        for(auto &it : s){
            if(mappedChar.find(it) == mappedChar.end())
                res += it;
        }      
        return res;
    }
};

class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(), [&](char a, char b)->bool{
            return order.find(a) < order.find(b);
        });
        return s;
    }
};