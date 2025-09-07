class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, common = 0;        
        for(int i = 0; i < nums.size(); i++){
            two |= one & nums[i];
            one ^= nums[i];
            
            common = ~(one & two);
            one &= common;
            two &= common;
        }

        return one;
    }
};