class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vec) {
        if(vec.size() == 0)
            return vector<vector<int>>{};
        
        sort(vec.begin(), vec.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        auto pit = vec.begin();
        auto cit = pit + 1;

        while (cit != vec.end()){
            vector<int>& pvec = *pit;
            vector<int>& cvec = *cit;
            if (cvec[0] <= pvec[1]){
                //merge;
                if(cvec[1] > pvec[1])
                    pvec[1] = cvec[1];
                cit = vec.erase(cit);
                continue;
            }

            pit = cit;
            cit++;
        }
        
        return vec;
    }
};