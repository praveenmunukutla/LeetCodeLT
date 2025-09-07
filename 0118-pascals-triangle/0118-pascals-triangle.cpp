class Solution {
    vector<vector<int>> res;
public:
    vector<int> generateUtil(int row){
        if(row == 1){
            res.push_back(vector<int>{1});
            return vector<int>{1};
        }
        
        vector<int> ret = generateUtil(row-1);
        vector<int> curr(row, 1);
        for(int i = 1; i < row - 1; i++)
            curr[i] = ret[i-1] + ret[i];
        
        res.push_back(curr);
        return curr;
    }
    
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return res;

        generateUtil(numRows);
        return res;
    }
};