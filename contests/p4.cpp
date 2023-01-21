#include <bits/stdc++.h>

using namespace std;

#define int                             long long
#define all(x)                          x.begin(), x.end()
#define sz(x)                           (int)x.size()
#define mset                            multiset
#define nl                              '\n'
#define mod97                           (int)(1E9+7)
#define mod53                           998244353
#define phi_const                       acos(-1)
#define infy_const                      (int)1e18+1
#define yes_no                          vector<string>{"No", "Yes"}
#define bstr_31(v)                      bitset<31>(v).to_string()
#define bstr_63(v)                      bitset<63>(v).to_string()
#define get_bit(v, i)                   ((v>>i)&1)
#define accum(v)                        accumulate(all(v), 0ll)
#define lbound(v, k)                    lower_bound(all(v), k)
#define ubound(v, k)                    upper_bound(all(v), k)
#define maxe(v)                         *max_element(all(v))
#define mine(v)                         *min_element(all(v))

typedef vector<int>                     vint;
typedef vector<vint>                    vvint;
typedef pair<int,int>                   pii;
typedef vector<pii>                     vpii;
typedef vector<vpii>                    vvpii;
typedef vector<bool>                    vbool;
typedef vector<string>                  vstr;
typedef vector<vvint>                   vvvint;
typedef vector<double>                  vd;
typedef vector<vd>                      vvd;
typedef vector<vvd>                     vvvd;

template<typename T>                    void read_input(T &v) { cin >> v; }
template<typename T1, typename T2>      void read_input(pair<T1, T2> &v) { cin >> v.first >> v.second; }
template<typename T>                    void read_input(vector<T> &arr) { for(auto &x: arr) read_input(x); }
template<typename T>                    void read_input(list<T> &arr) { for(auto &x: arr) read_input(x); }
template<typename T>                    void read_input(vector<vector<T>> &v) { for(auto &x : v) read_input(x); }
template<typename T, typename... VT>    void read_input(T &v, VT &...vars) { read_input(v); read_input(vars...); }

template<typename T>                    void output(T v) { cout << v << nl; }
template<typename T1, typename T2>      void output(pair<T1,T2> v) {cout << v.first << ' ' << v.second << nl;}
template<typename T>                    void output(vector<T> &v) { for(auto &x: v) cout << x << ' '; cout << nl; }
template<typename T>                    void output(list<T> &v) { for(auto &x: v) cout << x << ' '; cout << nl; }
template<typename T, typename... VT>    void output(T v, VT ...vars) { cout << v << ' '; output(vars...); }

void solve() {
    int n;
    read_input(n);
    vint arr(n);
    read_input(arr);

    auto calc_sq = [&](int x) {
        int ret = 0;
        for(auto &y : arr) {
            int v = sqrt(y + x);
            if(v*v == y + x || (v + 1) * (v + 1) == y + x) ret++;
        }
        return ret;
    };

    auto calc_sqness = [&](int i, int j) {
        int d = arr[j] - arr[i];
        int ret = 0;
        for(int p = 1; p * p <= d; p++) {
            if(d%p == 0) {
                int q = d / p;
                if(!((p+q)&1)) {
                    int b1 = (p + q) >> 1;
                    int b2 = (q - p) >> 1;
                    if(b1*b1 - arr[j] == b2*b2 - arr[i] && b1*b1 >= arr[j]) {
                        ret = max(ret, calc_sq(b1 * b1 - arr[j]));
                    }
                }
            }
        }
        return ret;
    };

    int ans = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = max(ans, calc_sqness(i, j));
        }
    }

    output(ans);
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
    read_input(tc);
    for(int c = 1; c <= tc; c++) {
        // cout << "Case #"<<c<<": ";
        solve();
    }
    return 0;
}
