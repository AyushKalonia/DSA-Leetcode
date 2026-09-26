class Solution {
public:
    bool solve(vector<int> &nums, int target, int indx, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }

        if(indx < 0 || target < 0){
            return false;
        }

        if(dp[indx][target] != -1)  return dp[indx][target];

        bool take = solve(nums, target-nums[indx], indx-1, dp);
        bool ntake = solve(nums, target, indx-1, dp);

        return dp[indx][target] = (take || ntake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i=0; i<n; i++){
            target += nums[i];
        }

        if(target%2 != 0)
            return false;
        
        else{
            target /= 2;
            vector<vector<int>> dp(n, vector<int>(target+1, -1));
            return solve(nums, target, n-1, dp);
        }

    }
};