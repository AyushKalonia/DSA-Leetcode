class Solution {
public:
    int solve(vector<int>& prices, int k, int indx, int buy, int cnt, vector<vector<vector<int>>> &dp){
        if(indx == prices.size())   return 0;
        if(cnt == k)    return 0;

        if(dp[indx][buy][cnt] != -1) return dp[indx][buy][cnt];

        int profit = 0;
        if(buy == 1){
            profit = max(solve(prices, k, indx+1, 0, cnt, dp) - prices[indx],
                            solve(prices, k, indx+1, 1, cnt, dp));
        }
        else{
            profit = max(solve(prices, k, indx+1, 1, cnt+1, dp) + prices[indx],
                            solve(prices, k, indx+1, 0, cnt, dp));
        }

        return dp[indx][buy][cnt] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (k+1, -1)));

        return solve(prices, k, 0, 1, 0, dp);
    }
};