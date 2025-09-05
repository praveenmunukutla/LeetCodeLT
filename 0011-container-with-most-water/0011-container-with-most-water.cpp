class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size()-1;
        int ans = INT_MIN;
        
        int minvalue, indexdiff, watersaved;
        while(first < last){
            //typical two pointer solution kindof;
            //take two height, first and last;
            //take the minimum height and calculate the index difference.
            //total water saved will be min height * index difference;
            //move the min height pointer;
            minvalue = min(height[first], height[last]);
            indexdiff = last - first;
            watersaved = minvalue * indexdiff;
            //cout<<minvalue<<" "<<indexdiff<<" "<<watersaved<<endl;
            if(minvalue == height[first])
                first++;
            else
                last--;
            ans = max(ans, watersaved);
        }
        return ans;
    }
};