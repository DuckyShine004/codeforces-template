#include <vector>

using namespace std;

/* NOTE: Can also consider using c-array */

/* Simple 1D segment tree with range sum query (inclusive range) */
struct Segtree {
    vector<int> t;
    int n;

    Segtree(const vector<int> &a, int n) : t(n << 2), n(n) {
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

    int query(int l, int r) {
        return Query(1, 0, n - 1, l, r);
    }

    int Query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) >> 1;
        int lq = Query(v << 1, tl, tm, l, min(r, tm));
        int rq = Query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(lq, rq);
    }

    void update(int pos, int val) {
        Update(1, 0, n - 1, pos, val);
    }

    void Update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                Update(v << 1, tl, tm, pos, val);
            else
                Update(v << 1 | 1, tm + 1, tr, pos, val);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }
};
