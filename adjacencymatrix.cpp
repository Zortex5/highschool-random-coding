#include <bits/stdc++.h>
#include "edge.hpp"

using std::cin, std::cout;

const int MAXN = 10; // max # of nodes
int n, m; // number of nodes and edges
int adj[MAXN][MAXN]; // adjacency matrix

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){ // for each of m edges
        int a, b;
        cin >> a >> b;
        a--; b--; // subtract 1 to maintain zero-indexing
        adj[a][b] = 1; // use weight if weighted graph
        adj[b][a] = 1; // omit line if graph is directed
    }
    return 0;
}