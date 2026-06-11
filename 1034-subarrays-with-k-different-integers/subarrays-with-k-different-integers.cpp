class Solution {
public:
    long long atMost(vector<int>& nums, int k){
        int left = 0;
        unordered_map<int, int> freq;
        long long cnt = 0;

        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
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