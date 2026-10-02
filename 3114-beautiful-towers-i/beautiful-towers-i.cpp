class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        
        long long maxi = 0;

        for(int i=0; i<n; i++){
            long long sum = 0;
            sum += heights[i];
            int indx = i-1;
            int last=heights[i];
            while(indx>=0){
                if(heights[indx]<=last){
                    sum+=heights[indx];
                    last = heights[indx];
                }
                else{
                    sum+=last;
                }
                indx--;
            }

            indx = i+1;
            last=heights[i];
            while(indx<n){
                if(heights[indx]<=last){
                    sum+=heights[indx];
                    last = heights[indx];
                }
                else{
                    sum+=last;
                }
                indx++;
            }
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};