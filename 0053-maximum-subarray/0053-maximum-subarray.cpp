#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0];
        int max_so_far = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr_max = MAX(nums[i] + curr_max, nums[i]);
            max_so_far = MAX(max_so_far, curr_max);
        }
        return max_so_far;
    }
};