class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int x : piles) {
            hours += ((long long)x + k - 1) / k;
        }
        return (hours <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (maxi < piles[i])
                maxi = piles[i];
        }
        int low = 1, high = maxi;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(piles, h, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};