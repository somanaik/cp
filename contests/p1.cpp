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
    ll minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vpll qmin, qmax;
        ll res = 0;
        for(int i = 0; i < n; i++) {
            while(!qmin.empty() && nums[i] <= nums[qmin.back().first]) qmin.pop_back();
            if(qmin.empty()) {
                qmin.push_back({i, (ll)(i+1)*nums[i]});
            } else {
                auto [j, sj] = qmin.back();
                qmin.push_back({i, (ll)(i - j)*nums[i]+sj});
            }

            while(!qmax.empty() && nums[i] >= nums[qmax.back().first]) qmax.pop_back();
            if(qmax.empty()) {
                qmax.push_back({i, (ll)(i+1)*nums[i]});
            } else {
                auto [j, sj] = qmax.back();
                qmax.push_back({i, (ll)(i - j)*nums[i]+sj});
            }
            int l = max(-1, i-k);
            auto v = make_pair(l, infy_ll);

            int j = upper_bound(all(qmin), v) - qmin.begin();
            res += qmin.back().second - qmin[j].second;
            res += (ll)(qmin[j].first - l) * nums[qmin[j].first];

            j = upper_bound(all(qmax), v) - qmax.begin();
            res += qmax.back().second - qmax[j].second;
            res += (ll)(qmax[j].first - l) * nums[qmax[j].first];
        }

        return res;
    }
};