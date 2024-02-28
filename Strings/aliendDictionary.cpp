class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 1; i < words.size(); i++){
            string first = words[i-1];
            string second = words[i];

            for(int j = 0; j < first.size(); j++){
                if(j == second.size())
                    return false;
                char firstChar = first[j];
                char secondChar = second[j];
                if(order.find(firstChar) < order.find(secondChar))
                    break;
                if(order.find(firstChar) > order.find(secondChar))
                    return false;
            }
        }
        return true;
    }
};

solution link: https://leetcode.com/problems/verifying-an-alien-dictionary/solutions/4794352/without-hashmap-clean-code-easy-explaination