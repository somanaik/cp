#include <bits/stdc++.h>

using namespace std;

#define int                             long long
#define pb                              push_back
#define pf                              push_front
#define all(x)                          x.begin(), x.end()
#define mkp                             make_pair
#define fst                             first
#define scd                             second
#define sz(x)                           (int)x.size()
#define mset                            multiset
#define ENDL                            '\n'
#define MOD97                           (int)(1E9+7)
#define MOD53                           998244353
#define PI                              acos(-1)
#define INFY                            (int)1e18+1
#define YES_NO                          vector<string>{"No", "Yes"}
#define bstr_31(v)                      bitset<31>(v).to_string()
#define bstr_63(v)                      bitset<63>(v).to_string()
#define get_bit(v, i)                   ((v>>i)&1)
#define accum(v)                        accumulate(all(v), 0ll)
#define lbound(v, k)                    lower_bound(all(v), k)
#define ubound(v, k)                    upper_bound(all(v), k)

typedef vector<int>                     vint;
typedef vector<vint>                    vvint;
typedef pair<int,int>                   pii;
typedef vector<pii>                     vpii;
typedef vector<vpii>                    vvpii;
typedef vector<bool>                    vbool;
typedef vector<string>                  vstr;

class shortest_path {

public:
    // non-negative weights
    static vint single(int src, vvpii &graph) {
        int n = sz(graph);
        vint dist(n, INFY);
        priority_queue<pii, vpii, greater<pii>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            // output(u, d);

            if(dist[u] > d) {
                dist[u] = d;
                for(auto &[v, w] : graph[u]) {
                    if(dist[v] > d + w) {
                        pq.push({d + w, v});
                    }
                }
            }
        }

        return dist;
    }

    static vint multi(vpii &srcs, vvpii &graph) {
        int n = sz(graph);
        vint dist(n, INFY);
        priority_queue<pii, vpii, greater<pii>> pq;
        for(auto &[u, d] : srcs) pq.push({d, u});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(dist[u] > d) {
                dist[u] = d;
                for(auto &[v, w] : graph[u]) {
                    if(dist[v] > d + w) {
                        pq.push({d + w, v});
                    }
                }
            }
        }

        return dist;
    }
};