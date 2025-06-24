class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        int i = 1;
        while(i<prices.size()){
            profit = max(profit,(prices[i]-mini));
            mini = min(mini,prices[i]);
            i++;
        }
        return profit;
    }
};