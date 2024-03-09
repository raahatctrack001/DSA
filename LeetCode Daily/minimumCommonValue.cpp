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

//one pass solution
//main aim is to reach close in values to each other as soon as possible
class Solution {
public:
    int getCommon(vector<int>& first, vector<int>& second) {
        int i = 0;
        int j = 0;
        int m = first.size();
        int n = second.size();

        while(i < m and j < n){
            if(first[i] == second[j])
                return first[i];
            else if(first[i] < second[j]){
                while(i < m and first[i] < second[j])
                    i++;
            }
            else{
                while(j < n and second[j] < first[i])
                    j++;
            }
        }
        return -1;
    }
};