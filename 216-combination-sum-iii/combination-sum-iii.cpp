class Solution {
public:
    void solve(int num, int cnt, int sum, int k, int n, vector<int> subset, vector<vector<int>> &ans){
        if (cnt == k) {
            if (sum == n) {
                ans.push_back(subset);
            }
            return;
        }

        if (num > 9 || sum > n) {
            return;
        }


        // take
        subset.push_back(num);
        solve(num + 1, cnt + 1, sum + num, k, n, subset, ans);
        subset.pop_back();

        // not take
        solve(num + 1, cnt, sum, k, n, subset, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;

        solve(1, 0, 0, k, n, subset, ans);

        return ans;
    }
};