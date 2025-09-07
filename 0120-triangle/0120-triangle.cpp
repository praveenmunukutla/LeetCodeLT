class Solution {
    vector<vector<int>> ntriangle;
    vector<vector<int>> cache;
    int nrow, ncol;
    int ans = INT_MAX;
public:
    int mpaths(int row, int col){
        if(row >= nrow)
            return 0;
        
        if(cache[row][col] != -1)
            return cache[row][col];

        return cache[row][col] = ntriangle[row][col] + 
                                 min(mpaths(row+1, col), mpaths(row+1, col+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        ntriangle = move(triangle);
        nrow = ntriangle.size();
        ncol = ntriangle[nrow-1].size();
        cache.resize(nrow, vector<int>(ncol, -1));
        return mpaths(0,0);
    }
};