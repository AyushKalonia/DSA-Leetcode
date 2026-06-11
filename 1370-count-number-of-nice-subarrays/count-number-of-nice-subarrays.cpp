class Solution {
        int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int left = 0;
        int oddCnt = 0;
        int arrCnt = 0;

        for (int right = 0; right < nums.size(); right++) {
            if(nums[right]%2 == 1)  oddCnt++;

            while (oddCnt > goal) {
                if(nums[left]%2==1) oddCnt --;
                left++;
            }

            arrCnt += right - left + 1;
        }

        return arrCnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atMost(nums, k) - atMost(nums, k-1));
    }
};