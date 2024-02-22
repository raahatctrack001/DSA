class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1)
            return 1;
            
        unordered_map<int, int> inDegree, outDegree;
        for(auto &relation : trust){
            inDegree[relation[1]]++;
            outDegree[relation[0]]++;
        }

        for(int i = 0; i <= n; i++)
            // (everyone-1 knows the judge) and (judge knows no one)
            if((inDegree[i] == n-1) and (outDegree[i] == 0))
                return i;
        
        return -1;
        
    }
};