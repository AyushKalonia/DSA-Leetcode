class Solution {
public:
    void solve(int n, int open, int close, string &s, vector<string> &ans, vector<vector<string>> &dp){
        if(s.length() == 2*n){
            ans.push_back(s);
            dp[open][close] = s;
            return;
        }

        if(dp[open][close] != "-1"){
            ans.push_back(dp[open][close]);
            return;
        }

        if(open < n){
            s.push_back('(');
            solve(n, open+1, close, s, ans, dp);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            solve(n, open, close+1, s, ans, dp);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<vector<string>> dp(n+1, vector<string>(n+1, "-1"));
        string s;

        solve(n, 0, 0, s, ans, dp);

        return ans;
    }
};