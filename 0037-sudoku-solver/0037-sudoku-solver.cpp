class Solution {
	vector<vector<char>> iboard;
public:
	bool getEmptyCell(int& x, int& y) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (iboard[i][j] == 0) {
					x = i, y = j;
					return true;
				}
			}
		}
		return false;
	}

	bool isValuePresentInRow(int row, int val) {
		for (int j = 0; j < 9; j++) {
			if (iboard[row][j] == val)
				return true;
		}
		return false;
	}

	bool isValuePresentInCol(int col, int val) {
		for (int i = 0; i < 9; i++) {
			if (iboard[i][col] == val)
				return true;
		}
		return false;
	}

	bool isValuePresentInSubgrid(int x, int y, int val) {
		int xs = (x / 3) * 3;
		int ys = (y / 3) * 3;
        //mistake 2 : xs + 3;
		for (int i = xs; i < xs + 3; i++) {
			for (int j = ys; j < ys + 3; j++) {
				if (iboard[i][j] == val)
					return true;
			}
		}
		return false;
	}

	bool canPlaceThisValue(int x, int y, int val) {
		return (isValuePresentInRow(x, val) == false) && 
			   (isValuePresentInCol(y, val) == false) && 
			   (isValuePresentInSubgrid(x,y,val) == false) && 
				iboard[x][y] == 0;
	}

	bool solveSudokuUtil() {
		int ex, ey;
		if (getEmptyCell(ex, ey) == false)
			return true;

        //mistake 1 = forgot <= 9 for list of numbers to be traversed.
		for (int i = 1; i <= 9; i++) {
			if (canPlaceThisValue(ex, ey, i)) {
				iboard[ex][ey] = i;
				if(solveSudokuUtil())
					return true;
				iboard[ex][ey] = 0;
			}
		}

		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		iboard.resize(9, vector<char>(9, 0));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					iboard[i][j] = 0;
				else
					iboard[i][j] = board[i][j] - '0';
			}
		}
		solveSudokuUtil();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				board[i][j] = iboard[i][j] + '0';
			}
		}
	}
};
