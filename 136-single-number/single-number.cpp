class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(int x: nums)    xor1 ^= x;
        return xor1;
    }
};