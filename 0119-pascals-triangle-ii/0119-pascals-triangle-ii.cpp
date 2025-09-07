class Solution {

public:

    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>{1};
        
        vector<int> res = getRow(rowIndex-1);
        vector<int> nres;
        nres.resize(res.size()+1);
        nres[0] = 1;
        nres[res.size()]=1;
        for(int i = 1; i < rowIndex; i++){
            nres[i] = res[i-1]+res[i];
        }
        return nres;
    }
};