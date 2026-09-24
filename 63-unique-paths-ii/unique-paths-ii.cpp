class Solution {
public:
    int solve(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(row == m-1 && col == n-1){
            if(obstacleGrid[row][col] == 1) return 0;
            else return 1;
        }
        if(row >= m || col >= n)  return 0;
        if(obstacleGrid[row][col] == 1) return 0;
        if(dp[row][col] != -1)  return dp[row][col];

        int down = solve(obstacleGrid, row+1, col, dp);
        int right = solve(obstacleGrid, row, col+1, dp);

        return dp[row][col] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(obstacleGrid, 0, 0, dp);
    }
};