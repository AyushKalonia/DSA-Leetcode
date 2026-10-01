class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0;
        int cnt = 0;
        for(auto x: nums){
            if(cnt == 0){
                cand = x;
            }

            if(x == cand){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return cand;
    }
};