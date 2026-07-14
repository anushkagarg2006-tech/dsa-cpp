class Solution {
public:
    bool found = false;
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        string current = "";
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                solve(board, word, i, j, current, visited);
                if(found) return true;
            }
        }
        return found;
    }
    
    void solve(vector<vector<char>>& board, string &word, int row, int col, 
                string &current, vector<vector<bool>> &visited){
        if(found) return;   // already mil chuka, aage mat jao
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() 
           || visited[row][col] || board[row][col] != word[current.length()])
            return;
        
        current.push_back(board[row][col]);   // string mein character add karo
        visited[row][col] = true;
        
        if(current == word){       // pura word ban gaya, match ho gaya
            found = true;
        } else {
            solve(board, word, row+1, col, current, visited);
            solve(board, word, row-1, col, current, visited);
            solve(board, word, row, col+1, current, visited);
            solve(board, word, row, col-1, current, visited);
        }
        
        current.pop_back();     // backtrack (undo)
        visited[row][col] = false;
    }
};