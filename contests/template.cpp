#include <bits/stdc++.h>

using namespace std;

#define phi_const               acos(-1)
#define infy_const              1e18+1

typedef vector<int>             vint;
typedef vector<vint>            vvint;
typedef pair<int,int>           pii;
typedef vector<pii>             vpii;
typedef vector<bool>            vbool;
typedef vector<string>          vstr;

int fast_io = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

// utility functions in matrix traversal
vvint _4dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vvint _8dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1,-1}, {-1, 1}, {1, -1}, {1, 1}};
vvint _lr_dir = {{1, 0}, {0, 1}};

int get_indx(int r, int c, int m) {
    return r * m + c;
}
pii get_cell(int id, int m) {
    return {id/m, id%m};
}
bool within_bounds(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

vvint mat_mult(vvint &m1, vvint &m2, int mod) {
    int a = m1.size(), b = m2.size(), c = m2.front().size();
    vvint res(a, vint(c));
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < c; j++) {
            for(int l = 0; l < b; l++) {
                res[i][j]+=m1[i][l]*m2[l][j]%mod;
            }
            res[i][j]%=mod;
        }
    }
    return res;
}

int nth_fibo(int n, int mod) {
    vvint res = {{1,0}, {0,1}}, mat = {{1,1}, {1,0}};
    while(n) {
        if(n&1) res = mat_mult(res, mat, mod);
        mat = mat_mult(mat, mat, mod);
        n>>=1;
    }
    return res[0][1];
}

vint fibonacci(int n, int mod) {
    vint fibs(n+1, 0);
    fibs[1] = 1;
    for(int i = 2; i <= n; i++) {
        fibs[i] = (fibs[i-1] + fibs[i-2]) % mod;
    }
    return fibs;
}

int lcm(int a, int b) {
    if(a == 0 && b == 0) return 0;
    return a*b / __gcd(a, b);
}

int lcm(vint &arr) {
    // TODO
    return -1;
}

// n >= 1
int closest_2pow(int n) {
    int ret = 1;
    while(ret <= n) ret<<=1;
    return ret>>=1;
}

vvint exp_mod(vvint &a, int e, int mod) {
    int n = a.size();
    vvint res(n, vint(n));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    while(e) {
        if(e&1) res = mat_mult(res, a, mod);
        a = mat_mult(a, a, mod);
        e>>=1;
    }
    return res;
}

int exp_mod(int a, int e, int mod) {
    if(mod == 1) return 0;
    int res = 1;
    while(e) {
        if(e&1) res = res * a % mod;
        e>>=1;
        a=a*a%mod;
    }
    return res;
}

int inv_mod(int b, int mod) {
    int a=mod, x=0, y=1, r, q;
    while(b) {
        r = a%b;
        q = a/b;
        a = b;
        b = r;
        r = x;
        x = y;
        y = r-q*y;
    }
    x+=mod;
    return x%mod;
}

bool is_prime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n&1)) return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

vbool calc_primes(int n) {
    vbool primes(n+1, true);
    primes[0] = primes[1] = false;
    for(int i = 4; i <= n; i+=2) primes[i] = false;
    for(int i = 3; i*i <= n; i+=2) {
        if(primes[i]) {
            for(int j = i * i; j <= n; j+=2*i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

vint calc_factorial(int n, int mod) {
    vint facts(n+1, 1);
    for(int i = 2; i <= n; i++) facts[i] = facts[i-1] * i % mod;
    return facts;
}

vint calc_inv_factorial(int n, int mod) {
    vint inv_facts(n+1, 1);
    for(int i = 2; i <= n; i++) {
        inv_facts[i] = inv_facts[i-1] * inv_mod(i, mod) % mod;
    }
    return inv_facts;
}

// it can be improved to n*log(n) from n*log(log(n))*log(n)
vint totient_of_1_to_n(int n) {
    vint tarr(n+1);
    iota(tarr.begin(), tarr.end(), 0);
    for(int i = 4; i <= n; i+=2) tarr[i] = 2;

    for(int i = 3; i*i <= n; i+=2) {
        if(tarr[i] == i) {
            for(int j = i * i; j <= n; j += (i << 1)) {
                tarr[j] = i;
            }
        }
    }
    
    for(int i = 2; i <= n; i++) {
        int j = tarr[i];
        while(i%j == 0) j*=tarr[i];
        j/=tarr[i];
        tarr[i] = tarr[i/j] * (j / tarr[i]) * (tarr[i] - 1);
    }

    return tarr;
}

vpii prime_factors_of_n(int n) {
    vpii pf_arr;
    int e = 0;
    while(!(n&1)) e++, n>>=1;
    if(e) pf_arr.push_back({2, e});
    for(int i = 3; i*i <= n; i+=2) {
        e = 0;
        while(n%i == 0) e++, n/=i;
        if(e) pf_arr.push_back({i, e});
    }
    if(n > 1) pf_arr.push_back({n, 1});
    return pf_arr;
}

vvint prime_factors_of_1_to_n(int n) {
    vvint pfacts(n+1);
    for(int i = 2; i <= n; i++) {
        if(pfacts[i].empty()) {
            for(int j = i; j <= n; j+=i) pfacts[j].push_back(i);
        }
    }
    return pfacts;
}

int totient_of_n(int n) {
    if(n < 2) return 0;
    int pf = 1, pf_1 = 1;
    for(auto [p, e] : prime_factors_of_n(n)) {
        pf = pf * p;
        pf_1 = pf_1 * (p - 1);
    }
    return (n / pf) * pf_1;
}

int divisors(int n) {
    int dvs = 1;
    for(auto [p, e] : prime_factors_of_n(n)) {
        dvs = dvs * (e + 1);
    }
    return dvs;
}

// number of i <= m coprime to n
int totient_of_n_less_m(int n, int m) {
    vpii pf = prime_factors_of_n(n);
    vint ss;
    for(auto &[p, e] : pf) {
        int k = ss.size();
        for(int i = 0; i < k; i++) {
            ss.push_back(ss[i]*(-p));
        }
        ss.push_back(p);
    }

    int ret = 0;
    for(auto &x : ss) {
        if(x < 0) ret -= m / abs(x);
        else ret += m / x;
    }

    return ret;
}

bool is_palin(string &s) {
    int n = s.size();
    for(int i = 0, j = n -1; i < j; i++,j--) {
        if(s[i] != s[j]) return false;
    }
    return true;
}

vint z_algo(string &s) {
    int n = s.size(), l = 0, r = 0;
    vint zarr(n, 0);
    for(int i = 1; i < n; i++) {
        if(r < i) {
            l = r = i;
            while(r < n && s[r-l] == s[r]) r++;
            zarr[i] = r - l;
            r--;
        } else {
            int k = i-l;
            if(zarr[k] < r-i+1) zarr[i] = zarr[k];
            else {
                l = i;
                while(r < n && s[r-l] == s[r]) r++;
                zarr[i] = r - l;
                r--;
            }
        }
    }

    return zarr;
}

// return slop of (x1, y1) and (x2, y2)
// return {1, 0} for vertical line and {0, 1} for horizontal
pii calc_slop(pii &p1, pii &p2) {
    int dx = p1.first-p2.first, dy = p1.second-p2.second;
    if(dx == 0) return {1,0};
    if(dy == 0) return {0,1};
    int g = gcd(abs(dx), abs(dy));
    dx/=g;
    dy/=g;
    if(dx < 0) dy=-dy, dx=-dx;
    return {dy, dx};    
}

// return 2 * area of convex n-gon
int calc_ngon_area(vpii &xy) {
    int n = xy.size(), area = 0;
    for(int i = 0; i < n; i++) {
        area += xy[i].first * xy[(i+1)%n].second - xy[(i+1)%n].first * xy[i].second;
    }
    return abs(area);
}

// ranges = [[l1, r1], [l2, r2], [l2, r3] ....], non-intersecting
bool split_range(map<int,int> &ranges, int v) {
    auto itr = ranges.upper_bound(v);
    if(itr != ranges.begin()) {
        itr--;
        if(itr->first <= v && v <= itr->second) {
            int a1 = itr->first, b1 = v - 1;
            int a2 = v + 1, b2 = itr->second;
            ranges.erase(itr);
            if(a1 <= b1) ranges[a1] = b1;
            if(a2 <= b2) ranges[a2] = b2;
            return true;
        }
    }
    return false;
}

int descrete_log(int a, int b, int m) {
    a %= m, b %= m;
    int n = sqrt(m) + 1;
    map<int, int> vals;
    for (int p = 1; p <= n; ++p)
        vals[exp_mod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (exp_mod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}

vector<vector<int>> palindrome_substrs(string &s) {
    int n = s.size();
    vector<vector<int>> ss_palin(n, vector<int>(n, -1));

    function<void(int,int)> helper = [&](int l, int r) {
        if(l > r) ss_palin[l][r] = 1;
        else if(l == r) ss_palin[l][r] = 1;
        else if(ss_palin[l][r] == -1) {
            if(s[l] != s[r]) ss_palin[l][r] = 0;
            else {
                helper(l+1, r - 1);
                ss_palin[l][r] = ss_palin[l+1][r-1];
            }
        }
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            helper(i, j);
        }
    }

    return ss_palin;
}

vvint divisors_of_1_to_n(int n) {
    vvint darr(n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j+=i) {
            darr[j].push_back(i);
        }
    }
    return darr;
}

// 1-index
bool can_2_color(vvint &adj) {
    int n = adj.size();
    vint color(n+1, -1);
    for(int i = 1; i <= n; i++) {
        
    }
}

signed main() {
    return 0;
}