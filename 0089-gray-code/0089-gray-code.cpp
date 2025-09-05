class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        n = 1 << n;
        for(int i = 1; i < n; i++){
            res.push_back(i ^ (i >> 1));
        }

        return res;
    }
};