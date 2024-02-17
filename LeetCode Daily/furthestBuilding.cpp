class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 1;
        priority_queue<int> pq;
        for(; i < heights.size(); i++){
            int currentDifference = heights[i]-heights[i-1];
            if(currentDifference <= 0) // no need to use either bricks or ladder
                continue;
            else{ // we can use either bricks or ladder here
                if(currentDifference <= bricks){ // if bricks can take u to next building
                    bricks -= currentDifference;
                    pq.push(currentDifference);
                }
                else{ //check if ladder can take u to the next Building
                    if(ladders > 0){
                        if(pq.size()){
                            int previousDifference = pq.top();
                            if(previousDifference > currentDifference){
                                //we will use ladder for previous route to minimise the loss of bricks as it will take more bricks
                                bricks += previousDifference;
                                
                                //using bricks for current route;
                                bricks -= currentDifference;
                                pq.pop();
                                pq.push(currentDifference);
                            }
                        }
                        ladders--; //using ladder for previous difference jump or current jump;
                    }
                    else //if neither bricks or ladder is left to take us to next buidling
                        break;
                }
            }
        }
        return i-1;    
    }
};