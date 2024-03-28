class Solution {
    bool isPossible(vector<int>& nums, vector<int>& quantity, int ithCustomer){
        if(ithCustomer >= quantity.size())
            return true;


        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= quantity[ithCustomer]){
                nums[i] -= quantity[ithCustomer];

                bool nextCustomer = isPossible(nums, quantity, ithCustomer+1);
                if(nextCustomer)
                    return true;

                nums[i] += quantity[ithCustomer];
            }
        }
        return false;
    }
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        sort(nums.begin(), nums.end());

        int count = 1;
        vector<int> freq;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                count++;
            else{
                freq.push_back(count);
                count = 1;
            }
        }    
        freq.push_back(count);
        sort(quantity.rbegin(), quantity.rend()); // to detect true condition faster!
        int ithCustomer = 0;
        return isPossible(freq, quantity, ithCustomer);

        return false;    
    }
};