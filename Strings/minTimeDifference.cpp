class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        //convert each time points in minutes
        for(auto &time : timePoints){
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3));

            int totalMinutes = hour*60 + minute;
            minutes.push_back(totalMinutes);
        }
        //sort them to reduce complexity of finding minimum
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for(int i = 1; i < minutes.size(); i++){
            int currentDiff = minutes[i]-minutes[i-1];
            minDiff = min(minDiff, currentDiff);
        }

        //till now we had compared each time stamps except for first and last one hence last difference goes this way
        //yahi fasoge bro!!! (this is where you gonna struggle bro!!!)
        int lastDiff = (minutes.front()+1440) - minutes.back();
        minDiff = min(minDiff, lastDiff);

        return minDiff;
        
    }
};