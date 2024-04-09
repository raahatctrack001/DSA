class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(true){
            for(int i = 0; i < tickets.size(); i++){
                if(!tickets[i])
                    continue;
                tickets[i]--;
                time++;
                if(!tickets[k])
                    return time;
            }
        }
        return time;
    }
};

//