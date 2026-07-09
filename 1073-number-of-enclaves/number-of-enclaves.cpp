class Solution {
public:
    int m;
    int n;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                grid[nr][nc] == 1) {
                dfs(nr, nc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid);
            }
            if (grid[i][n - 1] == 1) {
                dfs(i, n - 1, grid);
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j, grid);
            }
            if (grid[m - 1][j] == 1) {
                dfs(m - 1, j, grid);
            }
        }

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) cnt++;
            }
        }

        return cnt;
    }
};