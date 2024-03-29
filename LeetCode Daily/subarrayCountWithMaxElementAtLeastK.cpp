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

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {        
        int maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        vector<int> maxIndexContainer;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxElement)
                maxIndexContainer.push_back(i+1);
            if(maxIndexContainer.size() >= k){
                ans += maxIndexContainer[maxIndexContainer.size()-k];
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {        
        int maxElement = *max_element(nums.begin(), nums.end());
        long long int ans = 0;
        vector<int> maxIndexContainer;
        int count = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxElement)
                count++;

            while(count >= k){
                ans += nums.size()-i;
                if(nums[j] == maxElement)
                    count--;
                j++;
            }
        }
        
        return ans;
    }
};