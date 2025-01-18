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

bool is_palindrome(string &s) {
    vint freq(26);
    for(auto  &x : s) freq[x-'a']++;
    int c = 0;
    for(auto &x : freq) c += x&1;
    return c <= 1;
}

void solve() {
    int n;
    string s;
    input(n, s);
    vvint pos(26);
    for(int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    int o = -1;
    vint present;
    for(int i = 0; i < 26; i++) {
        int k = sz(pos[i]);
        if(k) present.push_back(i);
        if(k&1) {
            if(o != -1) {
                output(0);
                return;
            }
            o = i;
        }
    }

    int k = sz(present);
    if(k == 1) {
        output(-1);
        return;
    }

    auto calc_min = [&](int l, int c) {
        for(int i = c; i < 26; i++) {
            if(pos[i].empty() || pos[i].back() < l) continue;
            return i;
        }
        return -1;
    };


    string bres = string(n, 'z');
    auto brute = [&]() {
        for(int mask = 0; mask < (1<<n); mask++) {
            string t1 = "", t2 = "";
            for(int j = 0; j < n; j++) {
                if(get_bit(mask, j)) t1 += s[j];
                else t2 += s[j];
            }

            if(!is_palindrome(t2)) {
                if(t1.empty()) debug(mask);
                bres = min(bres, t1);
            }
        }
    };

    // all freq even
    string res = "";

    // brute();

    if(o == -1) {
        function<void(int)> rec = [&](int l) {
            int a = calc_min(l, 0);
            bool last = s.back() == 'a' + a;
            while(!pos[a].empty() && s.back() == 'a' + a) s.pop_back(), pos[a].pop_back();

            int m = 0;
            for(auto &y: pos[a]) m += y >= l;

            if(!m) {
                int b = calc_min(l, a + 1);
                res += 'a' + b;
                res += 'a' + a;
                return;
            }
            
            int b = calc_min(pos[a].back()+1, a + 1);
            if(m&1) {
                res += string(m, 'a' + a);
                res += 'a' + b;
                return;
            }
            if(last) {
                res += string(m, 'a' + a);
                res += 'a' + b;
                res += 'a' + a;
                return;
            }
            int c = calc_min(pos[a].back()+1, b + 1);
            if(c == -1) {
                pos[a].pop_back();
                b = calc_min(pos[a].back()+1, a + 1);
                res += string(m-1, 'a'+a);
                res += 'a'+b;
                return;
            }
            res += string(m, 'a' + a);
            rec(pos[a].back() + 1);
        };
        rec(0);
    } else {
        int a = present[0], b = -1, c = -1;
        if(a == o) {
            if(sz(pos[a]) == 1) {
                
            } else {
                
            }
        } else res += 'a' + a;
    }
    output(sz(res));
    // output(res, bres, yes_no[bres == res]);
    output(res);
    // cout << endl;
    // assert(bres == res);
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