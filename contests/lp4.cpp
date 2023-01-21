#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vlong;
typedef vector<vlong> vvlong;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

vector<bool> calc_primes(int n) {
    vector<bool> primes(n+1, true);
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

const int N = 1e6+10;
vector<bool> primes = calc_primes(N);

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int lp = -1, d = 1e9;
        vint ans = {-1, -1};
        for(int i = left; i <= right; i++) {
            if(primes[i]) {
                if(lp == -1) lp = i;
                else {
                    if(i - lp < d) {
                        ans = {lp, i};
                        d = i - lp;
                    }
                }
                lp = i;
            }
        }
        return ans;
    }
};