class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        long long leftSum = 0;
        long long rightSum = 0;

        for(int i=0; i<n; i++){
            leftSum = 0;
            rightSum = 0;
            for(int j=0; j<n; j++){
                if(j<i) leftSum += nums[j];
                if(j>i) rightSum += nums[j];
            }
            ans[i] = abs(leftSum-rightSum);
        }

        return ans;
    }
};