class Solution {
    int row,col;
    vector<vector<char>> mboard;
public:
    void check(int x, int y){
        if(x < 0 || x >= row || y < 0 || y >= col || mboard[x][y]=='X' || mboard[x][y] == 9)
            return;
        
        mboard[x][y] = 9;
        check(x-1,y);
        check(x, y+1);
        check(x+1,y);
        check(x, y-1);
    }
    
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if(row == 0)
            return;
        col = board[0].size();
        mboard = move(board);
        for(int i = 0; i < col; i++){
             check(0, i);
             check(row-1, i);
        }
        for(int i = 0; i < row; i++){
            check(i,0);
            check(i, col-1);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mboard[i][j] == 9)
                    mboard[i][j]='O';
                else
                    mboard[i][j]='X';
            }
        }
        board = move(mboard);
    }
};