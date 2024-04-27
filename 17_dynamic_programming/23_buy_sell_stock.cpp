/*
Problem: 
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

/*
Solution: Memoization
*/

int f(int i, int j, vector<int>& prices, vector<vector<int>>& dp) {
    if(i >= prices.size()) 
        return 0;
    if(dp[i][j] > -1) return dp[i][j];
    if(j == 0) {
        // can buy
        dp[i][j] = max(-prices[i] + f(i + 1, 1, prices, dp), // buy
        0 + f(i + 1, 0, prices, dp)); // not buy
    } else {
        // can sell
        dp[i][j] = max(prices[i] + f(i + 1, 0, prices, dp), // sell
        0 + f(i + 1, 1, prices, dp)); // not sell 
    }
    return dp[i][j];
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        f(0, 0, prices, dp);
        return dp[0][0];
    }
};

/*
Solution: Tabulation
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stocks = prices.size();
        int states = 2;
        vector<vector<int>> dp(stocks + 1, vector<int>(2, 0));
        // base conditions although unnecessary as already 0
        dp[stocks][0] = 0;
        dp[stocks][1] = 0;
        for(int i = stocks - 1; i >= 0; i--) {
            for(int j = 0; j < states; j++) {
                if(j == 0) {
                    // can buy
                    dp[i][j] = max(-prices[i] + dp[i + 1][1], // buy
                    0 + dp[i + 1][0]); // not buy
                } else {
                    // can sell
                    dp[i][j] = max(prices[i] + dp[i + 1][0], // sell
                    0 + dp[i + 1][1]); // not sell 
                }           
            }
        }
        return dp[0][0];
    }
};


/*
Problem Variation:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stocks = prices.size();
        int states = 4;
        vector<vector<int>> dp(stocks + 1, vector<int>(states + 1, 0));
        for(int i = stocks - 1; i >= 0; i--) {
            for(int j = 0; j < states; j++) {
                if(j % 2 == 0) {
                    // can buy
                    dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], // buy
                    0 + dp[i + 1][j]); // not buy
                } else {
                    // can sell
                    dp[i][j] = max(prices[i] + dp[i + 1][j + 1], // sell
                    0 + dp[i + 1][j]); // not sell 
                }           
            }
        }
        return dp[0][0];
    }
};


/*
Problem Variation:
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int stocks = prices.size();
        int states = 2 * k;
        vector<vector<int>> dp(stocks + 1, vector<int>(states + 1, 0));
        for(int i = stocks - 1; i >= 0; i--) {
            for(int j = 0; j < states; j++) {
                if(j % 2 == 0) {
                    // can buy
                    dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], // buy
                    0 + dp[i + 1][j]); // not buy
                } else {
                    // can sell
                    dp[i][j] = max(prices[i] + dp[i + 1][j + 1], // sell
                    0 + dp[i + 1][j]); // not sell 
                }           
            }
        }
        return dp[0][0];
    }
};

/*
Problem Variation:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stocks = prices.size();
        int states = 2;
        vector<vector<int>> dp(stocks + 2, vector<int>(states, 0));
        for(int i = stocks - 1; i >= 0; i--) {
            for(int j = 0; j < states; j++) {
                if(j == 0) {
                    // can buy
                    dp[i][j] = max(-prices[i] + dp[i + 1][1], // buy
                    0 + dp[i + 1][0]); // not buy
                } else {
                    // can sell
                    dp[i][j] = max(prices[i] + dp[i + 2][0], // sell
                    0 + dp[i + 1][1]); // not sell 
                }           
            }
        }
        return dp[0][0];
    }
};

/*
Problem Variation: 

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int stocks = prices.size();
        int states = 2;
        vector<vector<int>> dp(stocks + 1, vector<int>(states, 0));
        for(int i = stocks - 1; i >= 0; i--) {
            for(int j = 0; j < states; j++) {
                if(j == 0) {
                    // can buy
                    dp[i][j] = max(-prices[i] + dp[i + 1][1], // buy
                    0 + dp[i + 1][0]); // not buy
                } else {
                    // can sell
                    dp[i][j] = max(-fee + prices[i] + dp[i + 1][0], // sell
                    0 + dp[i + 1][1]); // not sell 
                }           
            }
        }
        return dp[0][0];
    }
};