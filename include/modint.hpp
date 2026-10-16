#include <iostream>

using namespace std;

template <int MOD> class ModInt {
    static_assert(MOD > 0);

    int v = 0;

  public:
    constexpr ModInt() = default;

    constexpr ModInt(long long x) {
        x %= MOD;
        if (x < 0)
            x += MOD;
        v = static_cast<int>(x);
    }

    constexpr int val() const {
        return v;
    }

    constexpr ModInt &operator+=(const ModInt &other) {
        long long sum = static_cast<long long>(v) + other.v;
        if (sum >= MOD)
            sum -= MOD;
        v = static_cast<int>(sum);
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt &other) {
        v -= other.v;
        if (v < 0)
            v += MOD;
        return *this;
    }

    constexpr ModInt &operator*=(const ModInt &other) {
        v = static_cast<int>(1LL * v * other.v % MOD);
        return *this;
    }

    friend constexpr ModInt operator+(ModInt a, const ModInt &b) {
        return a += b;
    }

    friend constexpr ModInt operator-(ModInt a, const ModInt &b) {
        return a -= b;
    }

    friend constexpr ModInt operator*(ModInt a, const ModInt &b) {
        return a *= b;
    }

    constexpr ModInt operator-() const {
        return ModInt(-v);
    }

    friend constexpr bool operator==(const ModInt &a, const ModInt &b) {
        return a.v == b.v;
    }

    friend constexpr bool operator!=(const ModInt &a, const ModInt &b) {
        return !(a == b);
    }

    friend ostream &operator<<(ostream &out, const ModInt &x) {
        return out << x.v;
    }
};
