class Solution {
    vector<int> num;
    vector<vector<int>> result;
public:
    
    void combination(int N, int R, int index, int i, vector<int>& temp){
        if(index == R){
            result.push_back(temp);
            return;
        }
        
        if(i >= N)
            return;

        temp.push_back(num[i]);
        combination(N, R, index + 1, i + 1, temp);
        temp.pop_back();
        combination(N, R, index, i + 1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        num = move(nums);
        result.push_back(vector<int>{});
        for(int i = 1; i <= size; i++) {
            vector<int> temp;
            combination(size, i, 0, 0, temp);
        }
        
        return move(result);
    }
};