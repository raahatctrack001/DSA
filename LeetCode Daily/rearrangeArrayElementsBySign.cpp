class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posNumbers;
        vector<int> negNumbers;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                posNumbers.push_back(nums[i]);
            else
                negNumbers.push_back(nums[i]);
        }

        vector<int> ans(nums.size());
        for(int i = 0, j = 0, k = 0; i < nums.size(); i++){
            if(i&1)
                ans[i] = negNumbers[k++];
            else
                ans[i] = posNumbers[j++];
        }
        return ans;
    }
};

class Solution {
    //idea: pick the number and place them in their correct position at first place
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      
       int n = nums.size();

       if(n == 0 or n == 1)
        return nums;
       vector<int> res(n, 0);
       int even = 0, odd = 1;
       for(int i = 0; i < n; i++){
           if(nums[i] >= 0){
               res[even] = nums[i];
                even = even+2;
           }else{
               res[odd] = nums[i];
                odd = odd+2;
           }
       }
       
        return res;        
    }
};