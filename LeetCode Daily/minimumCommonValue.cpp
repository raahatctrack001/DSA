class Solution {
    bool binarySearch(vector<int> &nums, int key){
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == key)
                return 1;
            else if(nums[mid] < key)
                start = mid+1;
            else
                end = mid-1;
        }
        return 0;
    }
public:
    int getCommon(vector<int>& first, vector<int>& second) {
        bool searchInFirst = first[0] < second[0];
        if(searchInFirst){
            for(int i = 0; i < second.size(); i++){
                bool result = binarySearch(first, second[i]);
                if(result)
                    return second[i];
            }
        }
        else{
            for(int i = 0; i < first.size(); i++){
                bool result = binarySearch(second, first[i]);
                if(result)
                    return first[i];
            }
        }
        return -1;
    }
};