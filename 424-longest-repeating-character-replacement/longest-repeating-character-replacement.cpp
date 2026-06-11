class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0, right = 0;
        int maxLen = 0, maxf = 0;

        while(right < s.length()) {
            freq[s[right] - 'A']++;
            maxf = max(maxf, freq[s[right] - 'A']);

            if ((right-left+1)-maxf > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};