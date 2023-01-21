#include <bits/stdc++.h>

using namespace std;

// 0-index
class union_find_rank {
    int _n;
    vector<int> _group_size;
    vector<int> _parent;
    int _ngroup;
public:
    union_find_rank(int n) : _n(n), _ngroup(n) {
        _group_size.resize(n, 1);
        _parent.resize(n);
        iota(_parent.begin(), _parent.end(), 0);
    }

    void join(int a, int b) {
        a = find_parent(a), b = find_parent(b);
        if(a != b) {
            if(_group_size[a] > _group_size[b]) {
                swap(a, b);
            }
            _parent[b] = a;
            _group_size[a] += _group_size[b];
            _ngroup--;
        }
    }

    int find_parent(int u) {
        if(_parent[u] == u) return u;
        return _parent[u] = find_parent(_parent[u]);
    }

    int get_size(int u) {
        u = find_parent(u);
        return _group_size[u];
    }

    bool connected(int u, int v) {
        u = find_parent(u);
        v = find_parent(v);
        return u == v;
    }

    int get_ngroup() {
        return _ngroup;
    }
};
