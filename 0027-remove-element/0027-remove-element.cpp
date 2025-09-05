class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        
        int sIndex  = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] == val)
                swap(nums[sIndex--], nums[i]);
        }
        
        return sIndex + 1;
    }
};