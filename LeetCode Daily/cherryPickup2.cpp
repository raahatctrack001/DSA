class Solution {
    int getMaxPickedCherry(vector<vector<int>> &cherryField, vector<vector<vector<int>>> &dp, int currentRow, int firstCol, int secondCol, int rowCount, int colCount ){
        if((currentRow >= rowCount) or (firstCol < 0 or secondCol < 0) or (firstCol >= colCount or secondCol >= colCount)){
            return 0;
        }
        if(dp[currentRow][firstCol][secondCol] != -1)
            return dp[currentRow][firstCol][secondCol];

        int cherriesPickedTillNow = INT_MIN;
        if(firstCol == secondCol){ //only one robot can take cherried of that cell hence i preferred first robot for this task;
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol-1, secondCol-1, rowCount, colCount));        
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol-1, secondCol, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol-1, secondCol+1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol, secondCol-1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol, secondCol, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol, secondCol+1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol+1, secondCol-1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol+1, secondCol, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol+1, secondCol+1, rowCount, colCount));
        }
        else{ //if first and second robore on different cell then take the cherries from both the cell
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol-1, secondCol-1, rowCount, colCount));        
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol-1, secondCol, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol-1, secondCol+1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol, secondCol-1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol, secondCol, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol, secondCol+1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol+1, secondCol-1, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol+1, secondCol, rowCount, colCount));
            cherriesPickedTillNow = max(cherriesPickedTillNow, cherryField[currentRow][firstCol] +cherryField[currentRow][secondCol] + getMaxPickedCherry(cherryField, dp, currentRow+1, firstCol+1, secondCol+1, rowCount, colCount));
        }
        return dp[currentRow][firstCol][secondCol] = cherriesPickedTillNow;
    }
public:
    //x, y coordinate, taking downward and rightward and positive axis;
    int cherryPickup(vector<vector<int>> &grid) {
        vector<vector<int>> cherryField = grid;
        int rowCount = grid.size();
        int colCount = grid[0].size();
        int currentRow = 0;
        int firstCol = 0;        
        int secondCol = colCount-1;
        vector<vector<vector<int>>> dp(rowCount+1, vector<vector<int>> (colCount+1, vector<int> (colCount+1, -1)));
        int maxPickedCherry = getMaxPickedCherry(cherryField, dp, currentRow, firstCol, secondCol, rowCount, colCount);
        return maxPickedCherry;
        
        
    }
};