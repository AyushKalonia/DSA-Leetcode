class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend > 0) == (divisor > 0);

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            int i = 0;

            while ((d << (i + 1)) <= n) {
                i++;
            }

            n -= (d << i);
            ans += (1LL << i);
        }

        if (ans > INT_MAX)
            return sign ? INT_MAX : INT_MIN;

        return sign ? ans : -ans;
    }
};
