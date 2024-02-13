class Solution {
    bool isPossible(vector<int> &position, int mid, int m){
        int ballsPlaced = 1;
        int lastPlacedPosition = position.front();

        for(int i = 0; i < position.size(); i++){
            if(position[i]-lastPlacedPosition >= mid){
                ballsPlaced++;
                lastPlacedPosition = position[i];
                if(ballsPlaced == m)
                    return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int start = 0;
        int end = position.back()-position.front();
        //search space start --- end

        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(position, mid, m)){
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
    }
};