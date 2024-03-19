class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //container for storing the frequencies of tasks : vector or map can also be used
        int frequencies[26] = {0};
        int maxFreq = INT_MIN;

        //storing frequencies and also updating maxFrequency simultaneously
        for(auto &task : tasks){
           maxFreq = max(maxFreq, ++frequencies[task-'A']);
        }
        
        int minMachineCyclesRequired = (maxFreq-1)*(n+1);

        for(auto &frequency : frequencies)
            if(frequency == maxFreq)
                minMachineCyclesRequired++;

        return max(minMachineCyclesRequired, (int)tasks.size());
    }
};