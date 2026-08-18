class Solution {
public:
    long long C(long long n) {
        if (n < 2) return 0;
        return n * (n - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        ans += C(n + 2);

        ans -= 3 * C(n - limit + 1);

        ans += 3 * C(n - 2LL * (limit + 1) + 2);

        ans -= C(n - 3LL * (limit + 1) + 2);

        return ans;
    }
};