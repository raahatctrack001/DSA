class Solution {
private:
    bool solve(vector<vector<char>> &board, string word, int i, int j, int k){
        if(k == word.size()) return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != word[k])
            return false;
        
        char ch = board[i][j];
        board[i][j] = '&';

        bool status = solve(board, word, i+1, j, k+1) or 
                        solve(board, word, i-1, j, k+1) or 
                        solve(board, word, i, j+1, k+1) or 
                        solve(board, word, i, j-1, k+1);
        board[i][j] = ch;
        return status;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if((board[i][j] == word[0]) and solve(board, word, i, j, 0))
                    return true;;
        return false;
    }
};

class Solution {
public:
    void print(vector<vector<char>> &board){
        // cout<<"current board after call \n";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<endl<<endl;
    }
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool solve(vector<vector<char>>& board, string word, int i, int j){
        if(word.empty()) 
            return true;
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size()){
            // cout<<"out of board call for: "<<i<<" "<<j<<endl;
            // print(board);
            return false;
        }
        if( board[i][j] != word.front()){
            // cout<<"alphabet didn't matched at: "<<i<<" "<<j<<endl;
            // print(board);
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '*';  
        // cout<<"call for: "<<i<<" "<<j<<endl;
        // print(board);
        bool status = false;
        for(auto direction: directions){
            int newX = i+direction.first;
            int newY = j+direction.second;
            status |= solve(board, word.substr(1), newX, newY);
        }
        board[i][j] = ch;
        // if(status){
        //     cout<<"Search is already completed and word is found! \n\n\n";
        // }
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool existence = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    existence = solve(board, word, i, j);
                    if(existence)
                        return true;
                }
            }
        }
        return false;
    }
};