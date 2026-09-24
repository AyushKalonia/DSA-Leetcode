class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){
        int n = triangle.size();
        if(row == n-1){
            return triangle[row][col];
        }
        
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int mini = INT_MAX;
        // i
        int sum = triangle[row][col] + solve(triangle, row+1, col, dp);
        mini = min(mini, sum);

        // i+1
        sum = triangle[row][col] + solve(triangle, row+1, col+1, dp);
        mini = min(mini, sum);

        return dp[row][col] = mini;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(triangle, 0, 0, dp);
    }
};