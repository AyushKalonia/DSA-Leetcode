class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int j = k;
        
        int maxi = 0;
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        maxi = sum;

        while(j<n){
            sum-=nums[j-k];
            sum+=nums[j];
            maxi = max(maxi, sum);
            j++;
        }
        
        return (double)maxi/k;
    }
};