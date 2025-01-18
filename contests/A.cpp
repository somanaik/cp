#include <bits/stdc++.h>

using namespace std;

#define ll                              long long
#define nl                              '\n'
#define mod97                           (int)(1e9+7)
#define mod53                           998244353
#define phi                             acos(-1)
#define infy_ll                         (ll)1e18+10
#define infy_int                        (int)1e9+10
#define yes_no                          vector<string>{"No", "Yes"}

#define all(x)                          x.begin(), x.end()
#define rall(x)                         x.rbegin(), x.rend()
#define sz(x)                           (int)x.size()
#define get_bit(v, i)                   ((v>>i)&1)
#define accum(v)                        accumulate(all(v), 0ll)
#define lbound(v, k)                    lower_bound(all(v), k)
#define ubound(v, k)                    upper_bound(all(v), k)

void __print(int x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(string x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename K, typename V> void __print(const pair<K,V> &x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second), cerr << '}'; }
template<typename T> void __print(const T &x) { int f = 0; cerr << '['; for(auto &v : x) cerr << (f++ ? "," : ""), __print(v); cerr << ']'; }

class _DEBUG {
private:
    int _pos;
    vector<string> _names;

    void _debug() { cerr << nl; };
    template<typename H, typename... T> void _debug(H h, T... t) {
        cerr << _names[_pos++] << " = ";
        __print(h);
        if(sizeof...(t)) cerr << ",";
        _debug(t...);
    }

    void _init(string &names) {
        _pos = 0;
        string s = "";
        for(auto &x: names) {
            if(x == ',') _names.push_back(s), s = "";
            else if(x != ',') s+=x; 
        }
        _names.push_back(s);
    }
public:
    template<typename... V> void dbg(string names, V... v) {
        _init(names);
        _debug(v...);
    }
};

#ifdef _BTN_LOCAL_JUDGE
#define debug(x...) _DEBUG().dbg(#x, x)
#else
#define debug(x...)
#endif

typedef vector<int>                     vint;
typedef vector<vint>                    vvint;
typedef pair<int,int>                   pii;
typedef pair<ll,ll>                     pll;
typedef vector<pii>                     vpii;
typedef vector<pll>                     vpll;
typedef vector<vpii>                    vvpii;
typedef vector<bool>                    vbool;
typedef vector<string>                  vstr;
typedef vector<ll>                      vll;
typedef vector<vll>                     vvll;

template<typename T>                    void input(T &v) { cin >> v; }
template<typename T1, typename T2>      void input(pair<T1, T2> &v) { cin >> v.first >> v.second; }
template<typename T>                    void input(vector<T> &arr) { for(auto &x: arr) input(x); }
template<typename T>                    void input(list<T> &arr) { for(auto &x: arr) input(x); }
template<typename T>                    void input(vector<vector<T>> &v) { for(auto &x : v) input(x); }
template<typename T, typename... VT>    void input(T &v, VT &...vars) { input(v); input(vars...); }

template<typename T>                    void output(T v) { cout << v << nl; }
template<typename T1, typename T2>      void output(pair<T1,T2> v) { cout << v.first << ' ' << v.second << nl; }
template<typename T>                    void output(vector<T> &v) { for(auto &x: v) cout << x << ' '; cout << nl; }
template<typename T>                    void output(list<T> &v) { for(auto &x: v) cout << x << ' '; cout << nl; }
template<typename T, typename... VT>    void output(T v, VT ...vars) { cout << v << ' '; output(vars...); }

int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng_int(seed);
mt19937_64 rng_ll(seed);

void solve() {
    int n, m;
    input(n, m);
    int x1 = 0, y1 = 0, x2 = m, y2 = m;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        input(x, y);
        int tx1 = x1 + x, ty1 = y1 + y;
        int tx2 = x2 + x, ty2 = y2 + y;

        res += 2*(tx2 - tx1 + ty2 - ty1);
        if(x1) {
            res -= 2*(x2 - tx1 + y2 - ty1);
        }

        x1 = tx1, x2 = tx2;
        y1 = ty1, y2 = ty2;
    }

    output(res);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
    input(tc);
    for(int c = 1; c <= tc; c++) {
        // cout << "Case #"<<c<<": ";
        solve();
    }
    return 0;
}