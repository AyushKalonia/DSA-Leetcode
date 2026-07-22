class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> blockStart, blockEnd, blockType, blockLen;
        vector<int> blockIdx(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            blockStart.push_back(i);
            blockEnd.push_back(j - 1);
            blockType.push_back(s[i] - '0');
            blockLen.push_back(j - i);
            int idx = (int)blockStart.size() - 1;
            for (int k = i; k < j; k++) blockIdx[k] = idx;
            i = j;
        }
        int m = blockStart.size();

        int totalOnes = 0;
        for (char c : s) totalOnes += (c - '0');   // <-- total ones in whole s

        const int NEG = -1;
        vector<int> val(m, NEG);
        for (int k = 0; k < m; k++) {
            if (blockType[k] == 1 && k > 0 && k < m - 1) {
                val[k] = blockLen[k - 1] + blockLen[k + 1];
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= m) LOG++;
        vector<vector<int>> sp(LOG, vector<int>(m, NEG));
        if (m > 0) sp[0] = val;
        for (int lvl = 1; lvl < LOG; lvl++) {
            int half = 1 << (lvl - 1);
            for (int k = 0; k + (1 << lvl) <= m; k++) {
                sp[lvl][k] = max(sp[lvl - 1][k], sp[lvl - 1][k + half]);
            }
        }
        vector<int> logTable(m + 1, 0);
        for (int k = 2; k <= m; k++) logTable[k] = logTable[k / 2] + 1;

        auto rangeMax = [&](int l, int r) -> int {
            if (l > r) return NEG;
            int len = r - l + 1;
            int lg = logTable[len];
            return max(sp[lg][l], sp[lg][r - (1 << lg) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int bi = blockIdx[l], bj = blockIdx[r];

            if (bi == bj || bj == bi + 1) {
                ans.push_back(totalOnes);
                continue;
            }

            int cl_bi = blockEnd[bi] - l + 1;
            int cl_bj = r - blockStart[bj] + 1;
            int best = 0;

            if (bj == bi + 2) {
                if (blockType[bi + 1] == 1) {
                    best = max(best, cl_bi + cl_bj);
                }
            } else {
                if (blockType[bi + 1] == 1) {
                    best = max(best, cl_bi + blockLen[bi + 2]);
                }
                if (blockType[bj - 1] == 1) {
                    best = max(best, blockLen[bj - 2] + cl_bj);
                }
                if (bj - 2 >= bi + 2) {
                    best = max(best, rangeMax(bi + 2, bj - 2));
                }
            }
            ans.push_back(totalOnes + best);
        }
        return ans;
    }
};