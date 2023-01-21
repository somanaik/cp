#include <bits/stdc++.h>

using namespace std;

template<class T, class U, T (*_mfunc)(T&, T&), T (*_cfunc)(int,U), T (*_ifunc)()> class segtree {
    private:
        int _n, _sn, _log;
        vector<T> _st;
        void _set(int _s, int _e, int _p, int _i, U& _v) {
            if(_s >= _e) _st[_p] = _cfunc(_i, _v);
            else {
                int _m = (_s + _e) >> 1;
                if(_i <= _m) _set(_s, _m, _p << 1, _i, _v);
                else _set(_m + 1, _e, _p << 1 | 1, _i, _v);
                _st[_p] = _mfunc(_st[_p << 1], _st[_p << 1 | 1]);
            }
        }

        T _get(int _s, int _e, int _p, int _l, int _r) const {
            if(_l <= _s && _e <= _r) return _st[_p];
            int _m = (_s + _e) >> 1;
            if(_r <= _m) return _get(_s, _m, _p << 1, _l, _r);
            if(_l > _m) return _get(_m + 1, _e, _p << 1 | 1, _l, _r);
            T _v1 = _get(_s, _m, _p << 1, _l, _m);
            T _v2 = _get(_m + 1, _e, _p << 1 | 1, _m + 1, _r);
            return _mfunc(_v1, _v2);
        }

        void _init() {
            _log = 0;
            while((1ll << _log) < _n) _log++;
            _sn = (1 << _log);
            _st = vector<T>(_sn << 1, _ifunc());
        }

        void _build(int _s, int _e, int _p, const vector<U>& _v) {
            if(_s >= _e) _st[_p] = _cfunc(_s, _v[_s]);
            else {
                int _m = (_s + _e) >> 1;
                _build(_s, _m, _p << 1, _v);
                _build(_m + 1, _e, _p << 1 | 1, _v);
                _st[_p] = _mfunc(_st[_p << 1], _st[_p << 1 | 1]);
            }
        }

    public:
        segtree() : segtree(0) {}
        segtree(int _nn) : _n(_nn) {
            _init();
        }
        segtree(const vector<U> &_v) : _n(sz(_v)) {
            _init();
            _build(0, _n - 1, 1, _v);
        }

        T operator [](int _p) const {
            assert(0 < _p && _p < (_sn << 1));
            return _st[_p];
        }

        // set arr[p] = v
        void set(int _p, U& _v) {
            assert(0 <= _p && _p < _n);
            _set(0, _n - 1, 1, _p, _v);
        }

        T get(int _l, int _r) const {
            assert(0 <= _l && _l <= _r && _r < _n);
            return _get(0, _n - 1, 1, _l, _r);
        }

        T get_all() const {
            return _st[1];
        }

        void build(const vector<U>& _v) {
            _n = _v.size();
            _init();
            _build(0, _n - 1, 1, _v);
        }
};

int _ifunc() {
    // TODO
    return 0;
}

int _cfunc(int i, int u) {
    // TODO
    return 0;
}

int _mfunc(int &v1, int &v2) {
    // TODO
    return 0;
}

signed main() {
    return 0;
}