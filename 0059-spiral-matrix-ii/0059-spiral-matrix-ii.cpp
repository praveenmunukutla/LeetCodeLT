class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> generateMatrix(int n) {
        res.resize(n, vector<int>(n,0));
        int row = 0, col = 0;
        int dir = 0; //0->right 1->bottom 2->left 3->top
        int i = 1;
        while(i <= n*n){
            res[row][col] = i;
            if(dir == 0){
                col++;
                if(col == n || res[row][col] != 0){
                    dir = 1;
                    col--;
                    row++;
                }
            }else if(dir == 1){
                row++;
                if(row == n || res[row][col] != 0){
                    dir = 2;
                    row--;
                    col--;
                }
            }else if(dir == 2){
                col--;
                if(col < 0 || res[row][col] != 0){
                    dir = 3;
                    col++;
                    row--;
                }
            }else if(dir == 3){
                row--;
                if(row < 0 || res[row][col] != 0){
                    dir = 0;
                    row++;
                    col++;
                }
            }
            i++;
        }
        
        return res;
    }
};