class Solution {
    vector<int> cand;
    vector<vector<int>> res;
    vector<int> tres;
public:
    void ways(int target, int index){
        if(target < 0 || index < 0)
            return;
        
        if(target == 0){
            res.push_back(tres);
            return;
        }
        
        //consider current element.
        tres.push_back(cand[index]);
        ways(target - cand[index], index);
        tres.pop_back();

        //dont consider current element.
        ways(target, index-1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = move(candidates);
        ways(target, cand.size()-1);
        return res;    
    }
};