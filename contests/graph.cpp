#include <bits/stdc++.h>

using namespace std;

#define phi_const               acos(-1)
#define infy_const              1e18+1

// template<typename E, typename W> struct edge {
//     E v;
//     W w;
//     edge(E _v): E(_v), w(0) {}
//     edge(E _v, W _w): v(_v), w(_w) {}
// };

// typedef edge<int,int>                       eii;
// typedef edge<int,long long>                 eil;
// typedef edge<pair<int,int>, int>            epi;
// typedef edge<pair<int,int>, long long>      epl;

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

// try to find topo sort. if does not exit, it will return partial topo sort
// 0-index
vector<int> topo_sort(vector<vector<int>> &g) {
    int n = g.size();
    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        for(auto &j: g[i]) d[j]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++) if(!d[i]) q.push(i);
    vector<int> ts;
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        ts.push_back(u);
        for(auto &v: g[u]) {
            d[v]--;
            if(d[v] == 0) q.push(v);
        }
    }
    return ts;
}