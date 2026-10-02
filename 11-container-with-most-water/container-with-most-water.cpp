class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxi = 0;

        int l = 0, r = n-1;
        
        while(l<r){
            int w = r-l;
            int h = min(height[l], height[r]);
            maxi = max(maxi, w*h);

            if(height[l] < height[r])   l++;
            else r--;
        }

        return maxi;
    }
};