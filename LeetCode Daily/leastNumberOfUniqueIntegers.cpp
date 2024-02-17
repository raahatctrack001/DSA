class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequencyTable;
        for(auto &num: arr)
            frequencyTable[num]++;

        vector<pair<int, int>> temp;
        for(auto &cell : frequencyTable){
            temp.push_back({cell.second, cell.first});
        }
        // sorting them on the basis of values as first value in vector is frequency;
        sort(temp.begin(), temp.end());

        for(auto &it : temp)
            {
                while(it.first and k > 0){
                    it.first--;
                    k--;
                }
                if(k <= 0)
                    break;
            }
        //if frequency is not zero then include that number only once
        int uniqueCount = 0;
        for(auto &it : temp){
            if(it.first)
                uniqueCount++;
        }
        return uniqueCount;

    }
};