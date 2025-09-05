class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return;
        int col = matrix[0].size();
        vector<int> r,c;
        r.resize(row, 0);
        c.resize(col, 0);
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    r[i]=1;
                    c[j]=1;
                }
            }
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(r[i] ==1 || c[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};