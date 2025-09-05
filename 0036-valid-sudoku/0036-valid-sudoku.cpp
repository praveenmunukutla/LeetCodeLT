class Solution {
    vector<vector<char>> ivboard;
public:
    	bool checkIsValid(int row, int col, int val) {
		int hcount = 0;
		for (int j = 0; j < 9; j++) {
			if (ivboard[row][j] == val)
				hcount++;
			if (hcount > 1)
				return false;
		}

		int vcount = 0;
		for (int i = 0; i < 9; i++) {
			if (ivboard[i][col] == val)
				vcount++;
			if (vcount > 1)
				return false;
		}

		int scount = 0;
		int rs = (row / 3) * 3;
		int cs = (col / 3) * 3;
		for (int x = rs; x < rs + 3; x++) {
			for (int y = cs; y < cs + 3; y++) {
				if (ivboard[x][y] == val)
					scount++;
				if (scount > 1)
					return false;
			}
		}

		return true;
	}

	bool isValidBoard() {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (ivboard[i][j] != 0) {
					if (checkIsValid(i, j, ivboard[i][j]) == false)
						return false;
				}
			}
		}
        return true;
	}
    
   bool isValidSudoku(vector<vector<char>>& board) {
		ivboard = move(board);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (ivboard[i][j] == '.')
					ivboard[i][j] = 0;
				else
					ivboard[i][j] = ivboard[i][j] - '0';
			}
		}


		return isValidBoard();
	}
};