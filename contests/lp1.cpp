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
    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for(auto &x : nums) {
            if(x > 0) p++;
            else if(x < 0) n++;
        }
        return max(p, n);
    }
};