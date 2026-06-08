class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int current, x;
        unordered_map<int, int> myMap;
        for (int i = 0; i < n; i++) {
            current = nums[i];
            x = target - current;
            if (myMap.find(x) != myMap.end())
                return {i, myMap[x]};
            myMap[current] = i;
        }
        return {-1, -1};
    }
};