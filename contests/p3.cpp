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
    int n, m = 26;
    string s;
    read_input(n, s);

    vint cpos[m];
    for(int i = 0; i < n; i++) cpos[s[i] - 'a'].push_back(i);
    vpii pvals;
    for(int i = 0; i < m; i++) {
        if(!cpos[i].empty()) {
            pvals.push_back({sz(cpos[i]), i});
        }
    }
    sort(pvals.rbegin(), pvals.rend());
    int k = sz(pvals);

    auto calc_diff = [&](int c, int f) {
        // cout << c << ' ' << f << endl;
        vint change(n, 0);
        vpii toc;
        if(c <= k) {
            for(int i = 0; i < c; i++) {
                int cnt = pvals[i].first;
                if(cnt < f) toc.push_back({pvals[i].second, f - cnt});
                else {
                    for(int j = 0; j < cnt - f; j++) {
                        change[cpos[pvals[i].second][j]] = 1;
                    }
                }
            }
            for(int i = c; i < k; i++) {
                for(auto &x : cpos[pvals[i].second]) {
                    change[x] = 1;
                }
            }
        } else {
            for(int i = 0; i < k; i++) {
                int cnt = pvals[i].first;
                if(cnt < f) toc.push_back({pvals[i].second, f - cnt});
                else {
                    for(int j = 0; j < cnt - f; j++) {
                        change[cpos[pvals[i].second][j]] = 1;
                    }
                }
            }

            int tk = k;
            for(int i = 0; i < m && tk < c; i++) {
                if(cpos[i].empty()) toc.push_back({i, f}), tk++;
            }
        }
        // output(change);
        // output(toc);

        string ts = s;
        int i = 0, j = 0;
        while(i < sz(toc) && j < n) {
            if(toc[i].second == 0) i++;
            else if(change[j]) {
                ts[j] = toc[i].first + 'a';
                toc[i].second--;
                j++;
            } else j++;
        }
        // cout << ts << endl;
        return make_pair(accum(change), ts);
    };

    int cost = infy_const;
    string bs = "";
    for(int c = 1; c <= m; c++) {
        if(n%c == 0) {
            int f = n / c;
            auto [tc, ts] = calc_diff(c, f);
            if(tc < cost) {
                cost = tc;
                bs = ts;
            }
        }
    }
    output(cost);
    output(bs);
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
