class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)    return {-1, -1};

        int low = 0, high = n - 1;
        int mid;

        int start=-1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                start = mid;
                high = mid-1;
            } else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        low = 0;
        high = n - 1;

        int end=-1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                end = mid;
                low = mid+1;
            } else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {start, end};
    }
};