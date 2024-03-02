//TC: O(nlogn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result = nums;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            result[i] = pow(result[i], 2);
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};

//TC: O(nlogn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //modifying original data isn't a good practice 
        vector<int> result = nums;
        sort(result.begin(), result.end(), [&](int &a, int &b)->bool{
            return abs(a) < abs(b);
        });

        for(auto &num: result)
            num  = num*num;
      
        return result;        
    }
};

//TC: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int index = nums.size()-1;
        vector<int> result(nums.size(), 0);
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right]))
                result[index] = nums[left]*nums[left++];
            else
                result[index] = nums[right]*nums[right--];
                
            index--;
        }
        return result;
    }
};