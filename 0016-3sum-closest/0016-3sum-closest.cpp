class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX, closeSum = 0;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int i,j,k,sum;
        for(i = 0; i < size-2; i++){
            j = i + 1, k = size-1;
            while(j < k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum == target){
                     return target;
                }else if(sum > target){
                    k--;
                }else{
                    j++;
                }
                int adiff = abs(target-sum);
                if(adiff < ans){
                    ans = adiff;
                    closeSum = sum;
                }
            }
        }
        
        return closeSum;    
    }
};