#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool dfs(int node, vector<int>& vis, int parent) {
    if (vis[node])
        return true;

    vis[node] = 1;

    for (auto &child : adj[node]) {
        if (child == parent)
            continue;

        if (dfs(child, vis, node))
            return true;
    }

    return false;
}

int main() {
    // rope x will connect nodes 2*x - 1 and 2*x
    // total nodes = 2*n
    // 2*x - 1 -> R
    // 2*x     -> B
    //Another way is to just check if each component nodes have degree == 2 
    //If lets say - each node needs to part of a cycle 
    //Problem - Check if each node is part of a cycle or not? One node can be part of multiple cycles.
    //In that case, there can only be articulation points ?idk
    //for which the condition becomes degree of all nodes in a connected component >= 2(idk) 
    //Answer - No, there can be bridges and that makes it invalid if there are >= 2 cycles 
    //So, for multiple cycles, its not valid
    int n, m;
    cin >> n >> m;

    adj.resize(2 * n + 1);

    for (int x = 1; x <= n; ++x) {
        adj[2 * x - 1].push_back(2 * x);
        adj[2 * x].push_back(2 * x - 1);
    }

    // connect operations
    for (int x = 1; x <= m; ++x) {
        int u, v;
        string cu, cv;

        cin >> u >> cu >> v >> cv;

        if (cu == "R")
            u = 2 * u - 1;
        else
            u = 2 * u;

        if (cv == "R")
            v = 2 * v - 1;
        else
            v = 2 * v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(2 * n + 1, 0);
    int cycle = 0, noncycle = 0;
    for(int x = 1; x <= 2*n; ++x){ 
        if(!vis[x]){
            if(dfs(x, vis, -1)) cycle++;
            else noncycle++;
        }
    }

    cout << cycle << " " << noncycle << "\n";
    return 0;
}