class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() ==1 ) return 0;
        int i = 0, n = prices.size();
        int ans = 0;
        // i ->buying products index , j->selling products index
        for(int j=1 ; j < n ;j++) { // moving j from 1 to (n-1)
            if(prices[i] < prices[j]) { // buying price is less than the selling price.... profit gaining
                int profit = prices[j] - prices[i]; 
                ans = max(profit, ans); // tracking the maximum profit
            }
            else{ 
        //selling price is less than or equal to buying price . so here loss is happening . But why cant we change this buying price as the next price. Since , j th index value has lesser product price then i th index.
                i = j;
            }
        }
        return ans;
    }
};