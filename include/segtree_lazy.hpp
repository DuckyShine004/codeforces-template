#include <vector>

using namespace std;

/* NOTE: Can also consider using c-array */

/* Simple 1D segment tree with range sum query (inclusive range) */
struct Segtree {
    vector<int> t, lazy;
    int n;

    Segtree(const vector<int> &a, int n) : t(n << 1), lazy(n << 1), n(n) {
        build(a, 1, 0, n - 1);
    }

    int combine(int a, int b) {
        return a + b;
    }

    void build(const vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(a, v << 1, tl, tm);
            build(a, v << 1 | 1, tm + 1, tr);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void push(int v, int tl, int tr) {
        int l = v << 1, r = v << 1 | 1, tm = (tl + tr) >> 1;
        t[l] += lazy[v] * (tm - tl + 1);
        lazy[l] += lazy[v];
        t[r] += lazy[v] * (tr - tm);
        lazy[r] += lazy[v];
        lazy[v] = 0;
    }

    void Update(int v, int tl, int tr, int l, int r, int x) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] += x * (tr - tl + 1);
            lazy[v] += x;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        Update(v << 1, tl, tm, l, min(r, tm), x);
        Update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void update(int l, int r, int x) {
        Update(1, 0, n - 1, l, r, x);
    }

    int Query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        int lq = Query(v << 1, tl, tm, l, min(r, tm));
        int rq = Query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(lq, rq);
    }

    int query(int l, int r) {
        return Query(1, 0, n - 1, l, r);
    }
};
