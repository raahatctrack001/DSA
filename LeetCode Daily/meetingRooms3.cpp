class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
       // sort meeting duration based on start Time
       // keep track of busy and free room
       // keep track of frequency of meeting held in particular room;

       /*To Do's in every iteration: 
        1. Dis engage all possible busy rooms;
        2. if room is free engage them 
        3. if room is not free handle waiting period i.e. dis engage on meeting's end and arrange 
        another meeting immediately.
        */

        sort(meetings.begin(), meetings.end());
        //pair<currentEndTime, roomNumber>
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> >busyRooms;
        //room numbers
        priority_queue<int, vector<int>, greater<int> >freeRooms;
        vector<int> roomFrequency(n, 0);

        for(int i = 0; i < n; i++)
            freeRooms.push(i);

        for(auto &duration : meetings){
            int startTime = duration[0];
            int endTime = duration[1];

            //1. dis engage all possible busy rooms
            while(busyRooms.size() > 0 and busyRooms.top().first <= startTime){
                //dis engaging is possible;
                int roomNumber = busyRooms.top().second;
                busyRooms.pop(); // dis engaged;

                //make it availabe
                freeRooms.push(roomNumber);
            }

            //2. if room is available
            if(freeRooms.size() > 0){
                int roomNumber = freeRooms.top();
                freeRooms.pop(); // not available now

                busyRooms.push({endTime, roomNumber});
                roomFrequency[roomNumber]++; //one more meeting in this room
            }
            else{ //3. handling waiting time when no room is avaialble
                auto nearEndMeeting = busyRooms.top();
                busyRooms.pop();

                roomFrequency[nearEndMeeting.second]++;

                long long newEndTime = nearEndMeeting.first + (endTime-startTime);
                busyRooms.push({newEndTime, nearEndMeeting.second});
            }
                
        }
        return max_element(roomFrequency.begin(), roomFrequency.end()) - roomFrequency.begin();
    }
};