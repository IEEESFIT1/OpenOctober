public class buySellStocks {
     public int maxProfit(int[] prices) {
        int buyPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
          //find the maximum profit
            profit = Math.max(prices[i] - buyPrice, profit);
          // buying price should be minimum for max profit
            buyPrice = Math.min(prices[i], buyPrice);
        }
        return profit;
    }
}
