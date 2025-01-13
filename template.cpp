#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#include "Debug.h"
#endif

using namespace std;
using namespace __gnu_pbds;

#define f first
#define s second
#define ppb pop_back
#define psb push_back
#define fors(i, a, b) for (auto i = a; i < b; i++)
#define revs(i, a, b) for (auto i = a; i > b; i--)
#define len(a) (a).length()
#define sz(a) (a).size()
#define vec1(type, n) vector<type>(n)
#define vec2(type, n, m) vector<vector<type>>((n), vector<type>((m)))
#define lsh(a) (1 << (a));
#define str(a) to_string(a)
#define ft front()
#define bk back()
#define all(a) (a).begin(), (a).end()
#define print(n) cout << n << " ";
#define println(n) cout << n << "\n";
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr), cout << fixed, cout << setprecision(10));

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const string ln = "\n";
const double PI = 3.14159265358979323846;
const ll INFLL = LLONG_MAX;
const pii d4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const pii d8[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, -1}};

template <typename T> void read(T &value) {
    cin >> value;
}

template <typename T> void read(vector<T> &arr) {
    for (auto &v : arr) {
        cin >> v;
    }
}

template <typename S, typename T> void read(pair<S, T> &p) {
    cin >> p.f >> p.s;
}

template <typename... Args> void input(Args &...args) {
    (read(args), ...);
}

template <typename T> T gcd(T a, T b) {
    return (b == 0) ? a : gcd(b, a % b);
}

template <typename T> bool in(const set<T> &s, T t) {
    return s.find(t) != s.end();
}

template <typename T> T sum(const vector<T> &v) {
    return accumulate(all(v), T(0));
}

template <class S, class T = null_type, class chash = hash<S>> using hset = gp_hash_table<S, T, chash>;
template <class S, class T = null_type, class cmp = less<S>> using oset = tree<S, T, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// Simple 1D range query segment tree inc range [a,b]
struct SegmentTree {
    vi st;

    SegmentTree(const vector<int> &a, int n) {
        st.resize(4 * n, 0);

        for (int i = 0; i < n; i++)
            st[n + i] = a[i];

        for (int i = n - 1; i >= 1; i--) {
            st[i] = st[i << 1] + st[i << 1 | 1];
        }
    }

    void update(int p, int v, int n) {
        p += n;

        st[p] = v;

        while (p > 1) {
            p >>= 1;
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
    }

    int query(int l, int r, int n) {
        l += n;
        r += n;

        int res = 0;

        while (l <= r) {
            if ((l & 1) == 1) {
                res += st[l++];
            }

            if ((r & 1) == 0) {
                res += st[r--];
            }

            l >>= 1;
            r >>= 1;
        }

        return res;
    }
};

struct UnionFind {
    vi reps;
    vi rank;

    UnionFind(int n) : reps(n), rank(n, 0) {
        fors(i, 0, n) {
            reps[i] = i;
        }
    }

    int find(int x) {
        while (x != reps[x]) {
            reps[x] = reps[reps[x]];
            x = reps[x];
        }

        return x;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        if (rank[x] > rank[y]) {
            reps[y] = x;
        } else {
            reps[x] = y;

            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
};

struct vec3 {
    double x, y, z;

    vec3() : x(0), y(0), z(0) {
    }

    vec3(double dx, double dy, double dz = 0) : x(dx), y(dy), z(dz) {
    }

    vec3 operator-() const {
        return vec3(-x, -y, -z);
    }

    double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    vec3 &operator-=(const vec3 &other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    vec3 &operator+=(const vec3 &other) {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    vec3 &operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;

        return *this;
    }

    vec3 &operator/=(double t) {
        x /= t;
        y /= t;
        z /= t;

        return *this;
    }
};

inline vec3 operator-(const vec3 &a, const vec3 &b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline vec3 operator+(const vec3 &a, const vec3 &b) {
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline vec3 operator*(const vec3 &a, double t) {
    return vec3(a.x * t, a.y * t, a.z * t);
}

inline vec3 operator*(const double t, const vec3 &a) {
    return a * t;
}

inline vec3 operator/(const vec3 &a, double t) {
    return vec3(a.x / t, a.y / t, a.z / t);
}

inline vec3 cross(const vec3 &a, const vec3 &b) {
    double dx = a.y * b.z - a.z * b.y;
    double dy = a.z * b.x - a.x * b.z;
    double dz = a.x * b.y - a.y * b.x;

    return vec3(dx, dy, dz);
}

inline double area(const vec3 &a, const vec3 &b, const vec3 &c) {
    return 0.5 * cross(b - a, c - a).magnitude();
}

int ord(char &c) {
    int x = int(c);

    if (!isalpha(c))
        return x - 48;

    return islower(c) ? x - 97 : x - 65;
}

void solve() {
}

int main() {
    fastio();

    /* int t = 1; */
    int t;
    cin >> t;

#ifdef DEBUG
    while (t--) {
        time__("Time") {
            solve();
        }
    }
#else
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    while (t--) {
        solve();
    }
#endif
}
