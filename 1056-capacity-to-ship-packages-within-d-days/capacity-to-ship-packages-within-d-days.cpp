class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int cap){
        int n=weights.size();
        int daysNeeded = 1;
        int curr=0;
        for(int x: weights){
            if(curr + x > cap){
                daysNeeded++;
                curr = x;
            }
            else curr += x;
        }
        return daysNeeded<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int sum = 0;
        for (int x : weights) {
            if (x > maxi)
                maxi = x;
            sum+=x;
        }

        int low = maxi, high = sum;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(weights, days, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};