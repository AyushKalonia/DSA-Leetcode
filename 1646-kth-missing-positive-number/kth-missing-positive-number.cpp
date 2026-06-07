class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int i=1, j=0;
        while(cnt<k){
            if(j<n && arr[j] == i) {
                i++;
                j++;
            }
            else{
                cnt++;
                if(cnt == k)    return i;
                i++;
            }
        }
        return -1;
    }
};