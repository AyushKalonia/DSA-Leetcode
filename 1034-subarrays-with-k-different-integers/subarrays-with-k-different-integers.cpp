class Solution {
public:
    long long atMost(vector<int>& nums, int k){
        vector<int> freq(nums.size() + 1, 0);
        int left = 0;
        int distinct = 0;
        long long cnt = 0;

        for(int right=0; right<nums.size(); right++){
            if(freq[nums[right]]++ == 0)    distinct++;
            while(distinct > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)   distinct--;
                left++;
            }

            cnt += (right-left+1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (int)(atMost(nums, k) - atMost(nums, k-1));
    }
};