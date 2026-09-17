#pragma GCC optimize("O3,inline")

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

#define all(a) (a).begin(), (a).end()
#define fastio() (ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr), cout << fixed, cout << setprecision(10));

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long, long>>;

inline constexpr double PI = 3.14159265358979323846;
inline constexpr pair<int, int> D4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
inline constexpr pair<int, int> D8[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, -1}};

template <typename T> string str(T a) {
    return to_string(a);
}

template <typename T> T gcd(T a, T b) {
    return (b == 0) ? a : gcd(b, a % b);
}

/* NOTE: For custom hash refer to https://gist.github.com/DuckyShine004/4dedbba84e0a9d77885d0cf1ea0e429f */
template <class S, class T = null_type, class chash = hash<S>> using hset = gp_hash_table<S, T, chash>;
template <class S, class T = null_type, class cmp = less<S>> using oset = tree<S, T, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
}

int main() {
    // FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    cout << fixed, cout << setprecision(10);

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
