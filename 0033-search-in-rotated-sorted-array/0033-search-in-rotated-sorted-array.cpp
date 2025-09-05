class Solution {
    vector<int> mnums;
    int mtarget;
public:
    int findPivot(int low, int high){
        if(low > high)
            return -1;

        int mid = (low + high) / 2;
        if(mid <  high && mnums[mid] > mnums[mid+1])
            return mid;
        if(mid > low && mnums[mid] < mnums[mid-1])
            return mid-1;
        
        if(mnums[low] <= mnums[mid])
            return findPivot(mid+1, high);
        return findPivot(low, mid-1);
    }
    
    int binarySearch(int low, int high){
        if(low > high)
            return -1;
        int mid = (low+high)/2;
        if(mnums[mid] == mtarget)
            return mid;
        
        if(mtarget > mnums[mid])
            return binarySearch(mid+1, high);
        
        return binarySearch(low, mid-1);
    }
    
    int search(vector<int>& nums, int target) {
        mnums = move(nums);
        mtarget = target;
        int index = findPivot(0, mnums.size()-1);
        if(index == -1)
            return binarySearch(0, mnums.size()-1);
        if(target >= mnums[0] && target <= mnums[index])
            return binarySearch(0, index);
        
        return binarySearch(index+1, mnums.size()-1);
    }
};