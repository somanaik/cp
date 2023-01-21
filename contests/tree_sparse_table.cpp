#include <bits/stdc++.h>

using namespace std;

class tree_sp_table {
	int _n, _root, _k, _timer;
	vector<vector<int>> _sp_table;
	vector<vector<int>> _tree;
	vector<int> _tin, _tout;

	void _build_sp_table(int u, int p) {
		_sp_table[u][0] = p;
		_tin[u] = ++_timer;
		for(int i = 1; i <= _k; i++) {
			_sp_table[u][i] = _sp_table[_sp_table[u][i-1]][i-1];
		}
        for(auto &v : _tree[u]) {
            if(v != p) _build_sp_table(v, u);
        }
        _tout[u] = ++_timer;
    }

    void _build_tree(vector<pair<int,int>> &edges) {
    	for(auto &e : edges) {
    		_tree[e.first].push_back(e.second);
    		_tree[e.second].push_back(e.first);
    	}
    }

    bool _is_ancestor(int u, int v) {
    	return _tin[u] <= _tin[v] && _tout[v] <= _tout[u];
    }

public:
	tree_sp_table(vector<vector<int>> &tree) {
		tree_sp_table(tree, 0);
	}

	tree_sp_table(vector<vector<int>> &tree, int root) : _n(tree.size()), _tree(tree), _root(root), _timer(0) {
		_k = ceil(log2(_n));
		_sp_table.assign(_n, vector<int>(_k+1));
    	_build_sp_table(_root, _root);
	}

	tree_sp_table(vector<pair<int,int>> &edges) {
		tree_sp_table(edges, 0);
	}

	tree_sp_table(vector<pair<int,int>> &edges, int root) : _n(edges.size() + 1), _root(root), _timer(0) {
		_k = ceil(log2(_n));
		_sp_table.assign(_n, vector<int>(_k+1));
		_tree.resize(_n);
		_build_tree(edges);
    	_build_sp_table(_root, _root);
	}

	// 0th ancestor is node itself
	// -1 if there is no kth ancestor
	int kth_ancestor(int u, int k) {
		if(k == 0) return u;
		int p = 0;
		for(int i = _k; i >= 0; i--) {
			if((k>>i)&1) u = _sp_table[u][i], p += (1<<i);
		}
		return p == k ? u : -1;
	}

	int lca(int u, int v) {
		if (_is_ancestor(u, v))
        	return u;
	    if (_is_ancestor(v, u))
	        return v;
	    for (int i = _k; i >= 0; --i) {
	        if (!_is_ancestor(_sp_table[u][i], v))
	            u = _sp_table[u][i];
	    }
	    return _sp_table[u][0];
	}
};
