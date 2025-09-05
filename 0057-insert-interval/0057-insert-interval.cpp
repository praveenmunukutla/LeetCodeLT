class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         intervals.push_back(newInterval);
         sort(intervals.begin(), intervals.end());
         auto it1 = intervals.begin();
         auto it2 = it1 + 1;
         while(it2 != intervals.end()){
             auto& v1 = *it1;
             auto& v2 = *it2;
             cout<<endl;
             if(v2[0] <= v1[1]){
                 if(v2[1] > v1[1]){
                     v1[1] = v2[1];
                 }
                 it2 = intervals.erase(it2);
             }else{
                 it1++;
                 it2++;
             }
         }
        
         return intervals;
    }
};