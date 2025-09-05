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
    
    int uniquePaths(int m, int n) {
        mgrid.resize(m, vector<int>(n,0));
        cache.resize(m, vector<int>(n,-1));
        row = m, col = n;
        return process(0,0);
    }
};