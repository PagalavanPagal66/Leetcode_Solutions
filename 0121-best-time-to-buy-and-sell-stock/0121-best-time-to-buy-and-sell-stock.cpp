class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int i = 0, j = 1;
        int ans = 0;
        while(j < prices.size()) {
            if(prices[i] < prices[j]) {
                int profit = prices[j] - prices[i];
                ans = max(profit, ans);
            }
            else i = j;
            j++;
        }
        return ans;
    }
};