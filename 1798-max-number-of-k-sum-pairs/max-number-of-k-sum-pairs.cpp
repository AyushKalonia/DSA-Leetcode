class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(mp[nums[i]] == 0)    continue;
            mp[nums[i]]--;

            int req = k-nums[i];
            if(mp[req]>0){
                cnt++;
                mp[req]--;
            }
        }

        return cnt;
    }
};