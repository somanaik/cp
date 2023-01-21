#include <bits/stdc++.h>

using namespace std;

class n_theory {
public:
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

    // n >= 1, 2^k <= n
    int closest_2pow(int n) {
        assert(n >= 1);
        int ret = 1;
        while(ret <= n) ret<<=1;
        return ret>>=1;
    }

    int lcm(int a, int b) {
        if(a == 0 && b == 0) return 0;
        return a * b / __gcd(a, b);
    }

    vector<bool> is_primes_1_to_n(int n) {
        vector<bool> b_primes(n+1, true);
        b_primes[0] = b_primes[1] = false;
        for(int i = 4; i <= n; i+=2) b_primes[i] = false;
        for(int i = 3; i*i <= n; i+=2) {
            if(b_primes[i]) {
                for(int j = i * i; j <= n; j+=2*i) {
                    b_primes[j] = false;
                }
            }
        }
        return b_primes;
    }

    vector<int> primes_1_to_n(int n) {
        vector<bool> is_primes_arr = is_primes_1_to_n(n);
        vector<int> primes;
        for(int i = 2; i <= n; i++) {
            if(is_primes_arr[i]) primes.push_back(i);
        }
        return primes;
    }

    vector<int> factorial_upto_n(int n, int mod) {
        vector<int> facts(n+1, 1);
        for(int i = 2; i <= n; i++) facts[i] = facts[i-1] * i % mod;
        return facts;
    }

    vector<int> factorial_inv_upto_n(int n, int mod) {
        vector<int> inv_facts(n+1, 1);
        for(int i = 2; i <= n; i++) {
            inv_facts[i] = inv_facts[i-1] * inv_mod(i, mod) % mod;
        }
        return inv_facts;
    }

    vector<pair<int,int>> prime_factors_of_n(int n) {
        vector<pair<int,int>> pf_arr;
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

    vector<vector<int>> prime_factors_upto_n(int n) {
        vector<vector<int>> pfacts(n+1);
        for(int i = 2; i <= n; i++) {
            if(pfacts[i].empty()) {
                for(int j = i; j <= n; j+=i) pfacts[j].push_back(i);
            }
        }
        return pfacts;
    }

    int totient_of_n(int n) {
        if(n < 2) return 0;
        for(auto &[p, e] : prime_factors_of_n(n)) {
            n = n / p;
            n = n * (p - 1);
        }
        return n;
    }

    vector<int> totient_upto_n(int n) {
        vector<int> tarr(n+1);
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
            int j = i / tarr[i];
            if(j%tarr[i] == 0) tarr[i] = tarr[j] * tarr[i];
            else tarr[i] = tarr[j] * (tarr[i] - 1);
        }

        return tarr;
    }

    int num_of_div_of_n(int n) {
        int dvs = 1;
        for(auto &[p, e] : prime_factors_of_n(n)) {
            dvs = dvs * (e + 1);
        }
        return dvs;
    }

    vector<int> num_of_div_upto_n(int n) {
        vector<int> d(n+1);
        for(int i = 1; i * i <= n; i++) {
            d[i*i]++;
            for(int j = i * (i + 1); j <= n; j+=i) {
                d[j]+=2;
            }
        }
        for(int i = 1; i <= n; i++) if(!d[i]) d[i]=2;
        return d;
    }
} nt;

int main() {

}