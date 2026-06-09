class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    if (r - l + 1 >= maxi) {
                        ans = s.substr(l, r - l + 1);
                        maxi = r - l + 1;
                    }
                } else
                    break;
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    if (r - l + 1 >= maxi) {
                        ans = s.substr(l, r - l + 1);
                        maxi = r - l + 1;
                    }
                } else
                    break;
                l--;
                r++;
            }
        }

        return ans;
    }
};