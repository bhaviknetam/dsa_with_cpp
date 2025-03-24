class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    long long binpow(int a, int b) {
        if (b == 0)
            return 1;
        long long t = binpow(a, b / 2);
        long long val = (t * t) % MOD;
        return (val * ((b & 1) ? a : 1ll)) % MOD;
    }
    int countOrders(int n) {
        long long val = binpow(2, n);
        long long inv = binpow(val, MOD - 2);
        long long ans = 1;
        for (int i = 2; i <= 2 * n; i++) {
            ans = (ans * 1ll * i) % MOD;
        }
        return (ans * inv) % MOD;
    }
};