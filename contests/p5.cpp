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
    vvint rects(n, vint(4));
    read_input(rects);

    auto merge_rects = [&](vint rpos) {
        if(!rpos.empty()) {
            sort(all(rpos), [&](int r1, int r2) {return rects[r1][1] < rects[r2][1];});
            int l = rects[rpos.front()][1], r = rects[rpos.front()].back();
            for(int i = 1; i < sz(rpos); i++) {
                int j = rpos[i];
                int tl = rects[j][1], tr = rects[j].back();
                if(tr <= r) rects[j] = vint(4, 0);
                else if(tl <= r) {
                    rects[j][1] = r + 1;
                    l = r + 1;
                    r = tr;
                } else l = tl, r = tr;
            }
        }
    };

    vint two_rows, one_rows[2];
    for(int i = 0; i < n; i++) {
        if(rects[i][0] != rects[i][2]) {
            two_rows.push_back(i);
        } else {
            one_rows[rects[i][0] - 1].push_back(i);
        }
    }

    // first merge rectangles covering both rows
    merge_rects(two_rows);
    vpii row_cover;
    for(auto &x : two_rows) {
        // not removed
        if(rects[x].front()) {
            if(row_cover.empty()) row_cover.push_back({rects[x][1], rects[x][3]});
            else {
                auto [l, r] = row_cover.back();
                int tl = rects[x][1], tr = rects[x][3];
                if(r + 1 == tl) row_cover.pop_back(), row_cover.push_back({l, tr});
                else row_cover.push_back({tl, tr});
            }
        }
    }

    // merge rectngles covering sigle row
    for(int i = 0; i < 2; i++) {
        merge_rects(one_rows[i]);

        // keep twos, reduce / remove ones
        int a = 0, b = 0;
        while(a < sz(row_cover) && b < sz(one_rows[i])) {
            int j = one_rows[i][b];
            if(!rects[j].front()) b++;
            else {
                int l = row_cover[a].first, r = row_cover[a].second;
                int tl = rects[j][1], tr = rects[j][3];
                if(tl < l) {
                    
                }
            }
        }
    }
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
