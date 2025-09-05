class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = n-1;
        for(int i = n-2;i>=0;i--){
            if(m-i<=nums[i]){
                m = i;
            }            
        }
        if(m==0){
            return true;
        }
        return false;
    }
};