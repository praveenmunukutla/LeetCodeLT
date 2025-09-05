
class Solution {
    vector<vector<int>> mgrid;
    vector<vector<int>> cache;
    int row, col;
public:
    inline bool isValid(int x, int y){
        if(x >= 0 && x < row && y >= 0 && y < col && mgrid[x][y] == 0)
            return true;
        return false;
    }
    
    int process(int x, int y){
        if(!isValid(x,y))
            return 0;
        
        if(cache[x][y] != -1)
            return cache[x][y];
        
        //cout<<x<<" "<<y<<endl;
        int temp = mgrid[x][y];
        mgrid[x][y] = 9;
        
        if(x == row - 1 && y == col - 1){
            mgrid[x][y] = temp;
            return 1;
        }
        
        int count = process(x+1, y) + process(x, y+1);
        mgrid[x][y] = temp;
        return cache[x][y] = count;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        mgrid = move(obstacleGrid);
        row = mgrid.size();
        col = mgrid[0].size();
        cache.resize(row,vector<int>(col,-1));
        return process(0,0);
    }
};