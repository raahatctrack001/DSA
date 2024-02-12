class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<pair<int, int> > differenceMap;
        //whatever the difference is coming we are mapping that difference with that number
        // let arr = 1,2,3,4,5: k = 4: x = 3
        //diff = abs(arr[i]-x); mapping = {diff, arr[i]} => mapping = {abs(arr[i]-x), arr[i]}
        // diff (1,3) is mapped as {abs(1-3), 1}
        // diff (2,3) is mapped as (1, 2)
        for(int i = 0; i < arr.size(); i++){
            int diff = abs(x-arr[i]);
            differenceMap.push_back({diff, arr[i]});
        }

        //sort the mapped vector to get difference value in ascending order so that we can extract first k number in different container
        sort(differenceMap.begin(), differenceMap.end());
        
        // extracting k closest element from mapped vector
        vector<int> KClosestElements(k);
        for(int i = 0; i < k; i++)
            KClosestElements[i] = differenceMap[i].second;
        
        sort(KClosestElements.begin(), KClosestElements.end());
        return KClosestElements;
        
        
    }
};