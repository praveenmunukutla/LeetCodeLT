class Solution {
    vector<vector<int>> result;
    vector<int> temp;
    vector<int> arr;
public:
    void combinationUtil(int n, int r, int i, int index){
        if(r == index){
            result.push_back(temp);
            return;
        }
        
        if(i >= n)
            return;
        
        temp.push_back(arr[i]);
        combinationUtil(n, r, i + 1, index + 1);
        temp.pop_back();
        combinationUtil(n, r, i + 1, index);
    }
    
    vector<vector<int>> combine(int n, int k) {
        arr.resize(n, 0);
        for(int i = 0; i < n; i++)
            arr[i] = i+1;
        combinationUtil(n, k, 0, 0);
        return result;
    }
};