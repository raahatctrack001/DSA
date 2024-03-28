class Solution {
public:
    void getArrangements(vector<int> &nums, int n, int current, int &beautifulArrangements){
        //base case
        if(current >= n+1){
            beautifulArrangements++;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(nums[i] == 0 and (current%i == 0 or i%current == 0)){
                nums[i] = current;
                getArrangements(nums, n, current+1, beautifulArrangements);

                nums[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> nums(n+1);
        int current = 1;
        int beautifulArrangements = 0;

        getArrangements(nums, n, current, beautifulArrangements);

        return beautifulArrangements;
    }
};