class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == n-1 && y == m-1)
                return effort;

            if(effort > dist[x][y])
                continue;

            for(int k=0;k<4;k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m){

                    int newEffort = max(
                        effort,
                        abs(heights[x][y] - heights[nx][ny])
                    );

                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }

        return 0;
    }
};