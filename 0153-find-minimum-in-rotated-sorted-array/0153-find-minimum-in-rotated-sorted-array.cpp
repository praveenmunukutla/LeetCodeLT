class Solution {
    vector<int> mnums;
public:
    
    int findPivot(){
        int low = 0, high = mnums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(mid < mnums.size() - 1 && mnums[mid] > mnums[mid+1])
                return mid;
            
            if(mnums[0] <= mnums[mid]){
                //first half is sorted;
                low = mid + 1;
            }else{
                //second half is sorted;
                high = mid - 1;
            }
        }

        return -1;
    }
    
    int findMin(vector<int>& nums) {
        mnums = move(nums);
        int index = findPivot();
        if(index == -1)
           return mnums[0];
        return mnums[index+1];
    }
};