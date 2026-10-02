class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> lmax(n);
        vector<int> rmax(n);

        for(int i=0; i<n; i++){
            if(i==0)    lmax[i]=height[i];
            else if(height[i]>lmax[i-1]) lmax[i]=height[i];
            else    lmax[i] = lmax[i-1];

            int k = n-1-i;
            if(k == n-1)    rmax[k]=height[k];
            else if(height[k]>rmax[k+1]) rmax[k]=height[k];
            else    rmax[k] = rmax[k+1];
        }

        int sum = 0;

        for(int i=0; i<n; i++){
            sum += min(lmax[i], rmax[i]) - height[i];
        }

        return sum;
    }
};