class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        int i=1, j=0;
        while(ans.size()<k){
            if(j<n && arr[j] == i) {
                i++;
                j++;
            }
            else    ans.push_back(i++);
        }
        return ans[k-1];
    }
};