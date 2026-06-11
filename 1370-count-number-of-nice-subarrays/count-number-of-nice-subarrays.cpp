class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int left = 0, right = 0;
        int oddCnt = 0;
        int arrCnt = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 == 1)
                oddCnt++;
            while (oddCnt > goal) {
                if (nums[left] % 2 == 1)
                    oddCnt--;
                left++;
            }
            arrCnt += right - left + 1;
            right++;
        }
        return arrCnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atMost(nums, k) - atMost(nums, k - 1));
    }
};