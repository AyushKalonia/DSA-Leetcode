class Solution {
public:
    int m;
    int n;

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater[0].size();

        vector<vector<int>> dis(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    dis[nr][nc] == -1) {

                    dis[nr][nc] = dis[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dis;
    }
};