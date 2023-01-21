#include <bits/stdc++.h>

using namespace std;

#define phi_const               acos(-1)
#define infy_const              1e18+1

// 0-index
vector<int> dist_from_root(vector<vector<int>> &tree, int r = 0) {
    int n = tree.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(r);
    dist[r] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto &v: tree[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

// 0-index
vector<int> euler_tour_of_tree(vector<vector<int>> &tree, int r = 0) {
    vector<int> tour;
    function<void(int,int)> dfs_helper = [&](int u, int p = -1) {
        tour.push_back(u);
        for(auto &v : tree[u]) {
            if(v != p) {
                dfs_helper(v, u);
                tour.push_back(u);
            }
        }
    };
    dfs_helper(r,-1);
    return tour;
}

// DFS tree, as adjacency list, of undirected connected graph with vertex r as root
// 0-index
vector<vector<int>> dfs_tree_as_adj(vector<vector<int>> &graph, int r = 0) {
    int n = graph.size();
    vector<vector<int>> tree(n);
    function<void(int,int)> dfs_helper = [&](int u, int p) {
        if(p != -1) {
            tree[u].push_back(p);
            tree[p].push_back(u);
        }
        for(auto &v : graph[u]) {
            if(v != p) {
                dfs_helper(v, u);
            }
        }
    };
    dfs_helper(r,-1);
    return tree;
}

// DFS tree, as parent array, of undirected connected graph with vertex r as root
// 0-index
vector<int> dfs_tree_as_array_of_parents(vector<vector<int>> &graph, int r = 0) {
    int n = graph.size();
    vector<int> parent(n);
    function<void(int,int)> dfs_helper = [&](int u, int p) {
        parent[u] = p;
        for(auto &v : graph[u]) {
            if(v != p) dfs_helper(v, u);
        }
    };
    dfs_helper(r, -1);
    return parent;
}

// BFS tree of undirected connected graph with vertex r as root
// 0-index
vector<vector<int>> bfs_tree(vector<vector<int>> &graph, int r = 0) {
    int n = graph.size();
    vector<vector<int>> tree(n);
    // TODO
    return tree;
}