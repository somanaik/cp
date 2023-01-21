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

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &x : nums) pq.push(x);
        ll ans = 0;
        while(k--) {
            ans += pq.top();
            int v = pq.top();
            pq.pop();
            pq.push((v + 2) / 3);
        }
        return ans;
    }
};