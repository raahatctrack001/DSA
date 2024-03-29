class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxElement = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            for(int j = i; j< nums.size(); j++){
                if(nums[j] == maxElement){
                    count++;
                    if(count >= k){
                        ans+= nums.size()-j;
                        cout<<ans<<" ";
                        break;
                    }
                }
            }
        }
        return ans;
    }
};