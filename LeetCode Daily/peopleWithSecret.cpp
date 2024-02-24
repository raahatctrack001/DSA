class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        //convert meetings into graphical representation i.e. adjacency list (weighted)
        unordered_map<int, list<pair<int, int> > >adjList;
        for(auto &meeting : meetings){
            int x = meeting[0];
            int y = meeting[1];
            int time = meeting[2];
            adjList[x].push_back({y, time});
            adjList[y].push_back({x, time});
        }
        //using priority queue to sort the meetings on the basis of shortest time (min heap)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, firstPerson});
        pq.push({0, 0});

        unordered_map<int, bool> isVisited;
        while(!pq.empty()){
            //taking out previosu meeting details
            auto prevMeeting = pq.top();
            int prevMeetingTime = prevMeeting.first;
            int messageCarrier = prevMeeting.second;
            pq.pop();

            //if message carrier has already spread the message
            if(isVisited[messageCarrier])
                continue;
            
            
            //if not then
            //we can't mark visited inside this loop as it will left many person unmarked due to its conditional entry
            isVisited[messageCarrier] = true;
            for(auto &currentMeeting : adjList[messageCarrier]){
                int currentMeetingTime = currentMeeting.second;
                int currentCarrier = currentMeeting.first;
                if(currentMeetingTime >= prevMeetingTime)
                    pq.push({currentMeetingTime, currentCarrier});
            }            
        }
        //visited person has a secret
        vector<int> ans;
        for(auto &it: isVisited)
            ans.push_back(it.first);

        return ans;        
    }
};