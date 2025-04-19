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
public:
    long long maxSubarrays(int n, vector<vector<int>>& cp) {
        vpii pts;
        for(auto &v : cp) {
            if(v.front() > v.back()) swap(v.front(), v.back());
            pts.push_back({v.back(), v.front()});
        }
        sort(all(pts));

        vpii tpts;
        int l = -1, r = -1;
        for(auto &[b, a]: pts) {
            if(a <= l) continue;
            if(l != -1) tpts.push_back({l, r});
            l = a, r = b;
        }

        
    }
};