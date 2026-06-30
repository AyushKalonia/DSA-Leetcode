class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int n = 1<<len;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int> list;
            for(int j=0; j<len; j++){
                if(i&(1<<j))    list.push_back(nums[j]);
            }
            ans.push_back(list);
        }
        return ans;
    }
};