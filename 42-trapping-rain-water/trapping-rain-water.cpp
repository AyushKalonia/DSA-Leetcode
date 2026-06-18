class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int lMax = 0, rMax = 0;
        int l = 0, r = n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(lMax > height[l])   ans += lMax-height[l];
                else    lMax = height[l];
                l++;
            }
            else {
                if(rMax > height[r])   ans += rMax-height[r];
                else    rMax = height[r];
                r--;
            }
        }

        return ans;
    }
};