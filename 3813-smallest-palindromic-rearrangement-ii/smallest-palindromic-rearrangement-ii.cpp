class Solution {
public:
    static const long long CAP = 4e18; // sentinel: "definitely >= any valid k"

    // Saturating multiply: returns min(a*b, CAP+1) without overflowing
    long long mulCap(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        if (a > CAP / b) return CAP + 1; // would overflow / exceed cap
        return a * b;
    }

    // Saturating C(n, r): safe because with r = min(r, n-r),
    // partial products C(n,1), C(n,2), ... C(n,r) are non-decreasing,
    // so once we exceed CAP we can stop early and return a sentinel.
    long long nCrCap(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            // res = res * (n - r + i) / i, done via __int128 for the one-step multiply
            __int128 tmp = (__int128)res * (n - r + i);
            tmp /= i;
            if (tmp > CAP) return CAP + 1;
            res = (long long)tmp;
        }
        return res;
    }

    long long countPermsHalf(int freq[26], int len) {
        long long result = 1;
        int remaining = len;
        for (int i = 0; i < 26; i++) {
            int f = freq[i];
            if (f == 0) continue;
            long long c = nCrCap(remaining, f);
            result = mulCap(result, c);
            remaining -= f;
            if (result > CAP) return CAP + 1;
        }
        return result;
    }

    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        int half = n / 2;
        bool oddExists = (n % 2 == 1);
        int oddChar = -1;

        int halfCnt[26];
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
            if (cnt[i] % 2 == 1) oddChar = i;
        }

        long long totalHalfPerms = countPermsHalf(halfCnt, half);
        if (k > totalHalfPerms) return "";

        string halfStr = "";
        int remainingFreq[26];
        for (int i = 0; i < 26; i++) remainingFreq[i] = halfCnt[i];
        int remainingLen = half;
        long long kk = k;

        for (int pos = 0; pos < half; pos++) {
            for (int c = 0; c < 26; c++) {
                if (remainingFreq[c] == 0) continue;
                remainingFreq[c]--;
                long long perms = countPermsHalf(remainingFreq, remainingLen - 1);
                if (kk <= perms) {
                    halfStr += (char)('a' + c);
                    remainingLen--;
                    break;
                } else {
                    kk -= perms;
                    remainingFreq[c]++;
                }
            }
        }

        string result = halfStr;
        if (oddExists) result += (char)('a' + oddChar);
        string rev = halfStr;
        reverse(rev.begin(), rev.end());
        result += rev;

        return result;
    }
};