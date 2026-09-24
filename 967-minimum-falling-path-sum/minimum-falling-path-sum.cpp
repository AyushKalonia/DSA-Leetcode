class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
        int n = matrix.size();

        if(row == n - 1)
            return matrix[row][col];

        if(dp[row][col] != INT_MAX)
            return dp[row][col];

        int mini = INT_MAX;

        
        for(int i=col-1; i<=col+1; i++){
            if(i>=0 && i<n){
                int points = matrix[row][col] + solve(matrix, row+1, i, dp);
                mini = min(mini, points);
            }
        }

        return dp[row][col] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        for(int col = 0; col < n; col++) {
            ans = min(ans, solve(matrix, 0, col, dp));
        }

        return ans;
    }
};