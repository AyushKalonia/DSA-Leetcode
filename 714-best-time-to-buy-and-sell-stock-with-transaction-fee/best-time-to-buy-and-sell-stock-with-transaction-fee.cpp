class Solution {
public:
    int solve(vector<int>& prices, int fee, int indx, int b, vector<vector<int>> &dp){
        if(indx == prices.size()){
            return 0;
        }
        
        if(dp[indx][b] != -1)  return dp[indx][b];
        
        int profit = 0;
        if(b == 1){
            profit = max( (solve(prices, fee, indx+1, 0, dp) - prices[indx]),
                                solve(prices, fee, indx+1, 1, dp) );
        }
        else{
            profit = max( (prices[indx] + solve(prices, fee, indx+1, 1, dp) - fee),
                                solve(prices, fee, indx+1, 0, dp) );
        }

        return dp[indx][b] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, fee, 0, 1, dp);
    }
};