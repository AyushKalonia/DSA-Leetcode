class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : pre) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int nxt : adj[node]) {
                if (--indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        return count == numCourses;
    }
};