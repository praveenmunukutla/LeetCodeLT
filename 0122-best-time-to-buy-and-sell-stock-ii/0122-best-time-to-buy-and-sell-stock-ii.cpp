class Solution {
    int ans = 0;
public:
    int maxProfit(vector<int>& prices) {
        for(int i = 1; i < prices.size(); i++){
            ans += max(prices[i]-prices[i-1], 0);
        }
        return ans;
    }
};