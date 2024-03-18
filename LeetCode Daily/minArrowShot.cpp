class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        
        int totalBallons = points.size();
        int arrowShot = 0;
        sort(points.begin(), points.end());
        pair<int, int> lastPoint = {points[0][0], points[0][1]};
        
        for(int i = 1; i < totalBallons; i++){
            pair<int, int> currentPoint = {points[i][0], points[i][1]};
            if(lastPoint.second >= currentPoint.first) //condition of intersection ? maximize this interval : (update count and do the same for currentPoint)
                lastPoint.second = min(lastPoint.second, currentPoint.second);
            else{
                lastPoint = currentPoint;
                arrowShot++;
            }
        }
        //if last intersection interval was found at last point then we have to upadate count explicitly
        return arrowShot+1;
    }
};