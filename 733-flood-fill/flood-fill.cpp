class Solution {
public:

    void dfsColor(vector<vector<int>>& image, int r, int c, int originalColor, int newColor){
        image[r][c] = newColor;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < image.size() &&
                nc >= 0 && nc < image[0].size() &&
                image[nr][nc] == originalColor) {

                dfsColor(image, nr, nc, originalColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;

        dfsColor(image, sr, sc, originalColor, color);
        return image;

    }
};