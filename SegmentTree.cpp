#define MAXN 100005
ll seg[4*MAXN];

void build(ll* arr, int in, int lo, int hi) {
    if(lo == hi) {
        seg[in] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo)/2;
    build(arr, 2*in + 1, lo, mid);
    build(arr, 2*in + 2, mid + 1, hi);
    seg[in] = seg[2*in + 1] + seg[2*in + 2];
}

ll query(int in, int lo, int hi, int l, int r) {
    if(lo >= l && hi <= r) {
        return seg[in];
    }
    if(hi < l || lo > r) {
        return 0;
    }
    int mid = lo + (hi - lo)/2;
    ll left = query(2*in + 1, lo, mid, l, r);
    ll right = query(2*in + 2, mid + 1, hi, l, r);
    return left + right;
}

void update(int in, int lo, int hi, int pos, int val) {
    if(lo == hi) {
        seg[in] = val;
        return;
    }
    int mid = lo + (hi - lo)/2;
    if(pos <= mid) {
        update(2*in + 1, lo, mid, pos, val);
    } else {
        update(2*in + 2, mid + 1, hi, pos, val);
    }

    seg[in] = seg[2*in + 1] + seg[2*in + 2];
}
