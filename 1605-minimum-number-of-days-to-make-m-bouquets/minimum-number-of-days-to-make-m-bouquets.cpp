class Solution {

public:
    int isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();
        int cnt = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (day >= bloomDay[i]) {
                curr++;
                if (curr == k) {
                    cnt++;
                    curr = 0;
                }
            } else
                curr = 0;
        }
        return cnt >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > n)
            return -1;

        int maxi = 0;
        int mini = INT_MAX;
        for (int x : bloomDay) {
            if (x > maxi)
                maxi = x;
            if (x < mini)
                mini = x;
        }

        int low = mini, high = maxi;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};