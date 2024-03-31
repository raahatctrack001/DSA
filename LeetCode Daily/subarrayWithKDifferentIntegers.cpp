int atMostKDistinct(vector<int>& nums, int k){
   int count = 0;
   int left = 0;
   int total = 0;
   unordered_map<int, int> mp;
   for(int right = 0; right < nums.size(); right++){
        mp[nums[right]]++;

        while(mp.size() > k){
            mp[nums[left]]--;
            if(mp[nums[left]] == 0)
                mp.erase(nums[left]);

            left++;
        }
        total += (right-left+1);
   }
   return total;
}


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        return atMostKDistinct(A, k) - atMostKDistinct(A, k-1);
    }
};