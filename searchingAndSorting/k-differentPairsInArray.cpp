//TC: O(n*2)
//n = size of array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int uniquePairs = 0;
        map<pair<int, int>, bool > isVisited;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(abs(nums[i]-nums[j]) == k){
                    if(isVisited.find({nums[i], nums[j]}) != isVisited.end())
                        continue;
                    else{
                        uniquePairs++;
                        isVisited[{nums[i], nums[j]}] = 1;
                        isVisited[{nums[j], nums[i]}] = 1;
                    }
                }
            }
        }

        return uniquePairs;
        
    }
};

//TC: O(m*logn)
//m = no of unique elements
//n = size of array
class Solution {
    int binarySearch(vector<int> &nums, int s, int e, int key){
        
        while( s<=e){
         int mid = s + (e-s)/2;
            if(nums[mid] == key)
                return mid;

            else if(nums[mid] > key)
                e = mid-1;

            else s= mid+1;
        }
        return -1;
    }
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // int count = 0;
        set<pair<int, int>> s;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i]+k;
            int ans = binarySearch(nums, i+1, nums.size()-1, key);
            if(ans != -1)
                s.insert({nums[i], nums[ans]});
        }
        return s.size();
    }
};  

//TC: O(n)
//n = size of array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int uniquePairs = 0;
        unordered_map<int, int> frequencyTable;
        
        for(auto &num : nums)
            frequencyTable[num]++;
        
        for(auto &num : frequencyTable){
            //abs(toFind - num.first) = k => toFind = k+num.first;
            int toFind = k+num.first;
            if(k == 0){
                if(num.second > 1) //if number exists more than once hence their unqiue pair x-x = 0;
                    uniquePairs++;
            }
            else if(frequencyTable.find(toFind) != frequencyTable.end())
                uniquePairs++;
        }
        return uniquePairs;
    }
};