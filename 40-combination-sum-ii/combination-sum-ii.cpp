class Solution {
public:
    void solve(vector<int>& candidates, int indx, int target, vector<int>& comb,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (indx == candidates.size() || target < 0) {
            return;
        }


        // take
        comb.push_back(candidates[indx]);
        solve(candidates, indx+1, target - candidates[indx], comb, ans);
        comb.pop_back();

        int next = indx + 1;
        while (next < candidates.size() && candidates[next] == candidates[indx])
            next++;


        // not take
        solve(candidates, next, target, comb, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
    
        vector<vector<int>> ans;
        vector<int> comb;

        solve(candidates, 0, target, comb, ans);
        return ans;
    }
};