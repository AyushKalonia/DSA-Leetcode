class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int start = 0; start < n; start++) {
            if (visited[start]) {
                continue;
            }

            queue<int> q;
            q.push(start);
            visited[start] = true;

            long long vertexCount = 0;
            long long degreeSum = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                vertexCount++;
                degreeSum += adj[node].size();

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            // A complete component with k vertices has
            // total degree = k * (k - 1).
            if (degreeSum == vertexCount * (vertexCount - 1)) {
                completeComponents++;
            }
        }

        return completeComponents;
    }
};