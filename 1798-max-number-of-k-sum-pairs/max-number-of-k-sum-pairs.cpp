class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int cnt = 0;

        for(int i=0; i<n; i++){
            int req = k-nums[i];
            if(mp[req] > 0) {
                cnt++;
                mp[req]--;
            }
            else {
                mp[nums[i]]++;
            }

        }

        return cnt;
    }
};