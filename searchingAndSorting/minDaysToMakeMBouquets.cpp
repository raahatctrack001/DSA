class Solution {
    bool isPossible(vector<int> &bloomDay, int possibleDuration, long m, long k){
        int flowersCollected = 0;
        int bouquetsCollected = 0;
        for(auto &day : bloomDay){
            //checking if flower has been bloomed for collection
            if(day <= possibleDuration){
                flowersCollected++;
            }
            else{
                //now this time flower isn't bloomed hence check how many bouquets can be made from this much flower collection.
                bouquetsCollected += flowersCollected/k;
                //start collecting flowers again
                flowersCollected = 0;
            }
        }
        //add the possible bouquets 
        bouquetsCollected += flowersCollected/k;
        return bouquetsCollected >= m;
    }
public:
    int minDays(vector<int>& bloomDay, long m, long k) {
        //if no of flowers needed exceeds the number of available flowers after complete blooming

        if(m*k > bloomDay.size())
            return -1;
        int minDay = INT_MAX;
        int maxDay = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] > maxDay)
                maxDay = bloomDay[i];
            else if(bloomDay[i] < minDay)
                minDay = bloomDay[i];
        }
        //now search space lies between minDay --- maxDay;
        // we can also take search space as 0 --- maxDay, it doesn't matter much;
        int ans = -1;
        while(minDay <= maxDay){
            //checking whether this day is enough to make sufficent bouquets
            int currentDuration = (minDay + maxDay)/2;
            if(isPossible(bloomDay, currentDuration, m, k)){
                //if yes explore another minimum duration possibility
                ans = currentDuration;
                maxDay = currentDuration-1;
            }
            else
                minDay = currentDuration+1;
        }
        return ans;
    }
};