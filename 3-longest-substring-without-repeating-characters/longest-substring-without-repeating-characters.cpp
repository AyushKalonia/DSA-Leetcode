class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        vector<int> last(256, -1);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            if (last[s[right]] != -1) {
                left = max(left, last[s[right]] + 1);
            }

            last[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};