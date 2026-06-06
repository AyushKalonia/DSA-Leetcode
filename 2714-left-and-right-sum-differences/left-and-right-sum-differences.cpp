class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return {};
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = abs(2*prefix[i] - nums[i] - prefix[n-1]);
        }

        return ans;
    }
};