class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Sort nodes according to nums[i].
        vector<int> order(n);

        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // value[i] = ith smallest value
        // position[node] = node's index in sorted order
        vector<int> value(n);
        vector<int> position(n);

        for (int i = 0; i < n; i++) {
            value[i] = nums[order[i]];
            position[order[i]] = i;
        }

        int LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        // jump[k][i]:
        // Farthest sorted index reachable from i
        // using at most 2^k edges.
        vector<vector<int>> jump(LOG, vector<int>(n));

        // Build jump[0] using two pointers.
        int right = 0;

        for (int left = 0; left < n; left++) {
            right = max(right, left);

            while (
                right + 1 < n &&
                value[right + 1] - value[left] <= maxDiff
            ) {
                right++;
            }

            jump[0][left] = right;
        }

        // Build binary-lifting table.
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[k][i] =
                    jump[k - 1][jump[k - 1][i]];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& query : queries) {
            int left = position[query[0]];
            int target = position[query[1]];

            if (left > target) {
                swap(left, target);
            }

            // Same node requires zero edges.
            if (left == target) {
                answer.push_back(0);
                continue;
            }

            int current = left;
            int distance = 0;

            // Use the largest possible jumps while
            // staying strictly before the target.
            for (int k = LOG - 1; k >= 0; k--) {
                int nextPosition = jump[k][current];

                if (
                    nextPosition > current &&
                    nextPosition < target
                ) {
                    current = nextPosition;
                    distance += (1 << k);
                }
            }

            // Check whether one final edge reaches target.
            if (jump[0][current] >= target) {
                answer.push_back(distance + 1);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};