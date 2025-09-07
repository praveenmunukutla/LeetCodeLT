class Solution {
    int ans = 0;
    int mval = 0;
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        mval = prices[prices.size()-1];
        for(int i = prices.size()-1; i >= 0; i--){
            if(mval > prices[i]){
                ans = max(ans, mval - prices[i]);
            }
            mval = max(mval, prices[i]);
        }
        return ans;
    }
};