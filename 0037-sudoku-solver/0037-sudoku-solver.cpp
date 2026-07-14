class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(issafe(board,ch,i,j)){
                            board[i][j]=ch;
                           if( solve(board)) return true;
                           board[i][j]='.';
                        }

                    }return false;
                }
            }
        }return true;
    }
    bool issafe(vector<vector<char>> &board,char ch,int i,int j){
        for(int a=0;a<9;a++){
            if(board[a][j]==ch)return false;
        
            if(board[i][a]==ch)return false;
        
        
            int boxRow = 3*(i/3) + a/3;
            int boxCol = 3*(j/3) + a%3;
            if(board[boxRow][boxCol] == ch) return false;
        }
        return true;
    }
};