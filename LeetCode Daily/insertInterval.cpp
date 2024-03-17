class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;
        int n = intervals.size();
            //To Do's: In merge interval type of problems only these three cases needs to be handled;
            //case1: Handle non overlapping section
            //case2: Handle overlapping section
            //case3: Append rest of interval as no action required

            //case 1
            while(i < n and intervals[i][1] < newInterval[0]){
                answer.push_back(intervals[i]);
                i++;
            }

            //case 2
            int start = newInterval[0];
            if(i<n)
                start = min(newInterval[0], intervals[i][0]);
            int end = newInterval[1];
            while(i < n and newInterval[1] >= intervals[i][0]){
                end = max(newInterval[1], intervals[i][1]);
                i++;
            }
            answer.push_back({start, end});

            //case 3
            while(i < n){
                answer.push_back(intervals[i]);
                i++;
            }

        return answer;
    }
};


/*
1. case for including non overlapping intervals before merging i.e. intervals shorter than new Interval
condition: if(i < n and intervals[i][1] < newIntervals[0])

2. case for handling overlapping intervals: take maximum at end and minimum at start [start, end]
condition: if(i < n and intervals[i][0] <= newInterval[1]){
    newInterval[0] = min(newInterval[0], intervals[i][0])
    newInterval[1] = max(newInterval[1], interval[i][1])
}

3. include rest of the intervals as no action needed for them:
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;
        int n = intervals.size();

        //1. directly include intervals which are not overlapping
        while(i < n and intervals[i][1] < newInterval[0]){
            answer.push_back(intervals[i++]);
        }

        // 2. handle overlapping case
        while(i < n and intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        answer.push_back(newInterval);

        // 3. handling non overlapping cases after merging interval
        while(i < n)
            answer.push_back(intervals[i++]);

        return answer;
    }
};