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