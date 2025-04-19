#include <bits/stdc++.h>

using namespace std;

#define ll                              long long
#define mod97                           (int)(1e9+7)
#define mod53                           998244353
#define phi                             acos(-1)
#define infy_ll                         (ll)1e18+10
#define infy_int                        (int)1e9+10
#define all(x)                          x.begin(), x.end()

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

class Solution {
    void solve() {
        unordered_map<int, int> dp;
        dp[1] = 1;
        for(int i = 0; i < n; i++) {
            unordered_map<int,int> new_dp = dp;
            for(auto [j, sc]: dp) {
                j*=a[i];
                if(k%j == 0) new_dp[j] += sc;
            }
            dp = new_dp;
        }
        ll ans = 0;
        for(auto [j, sc]: dp) {
            ans += sc;
        }
    }
};