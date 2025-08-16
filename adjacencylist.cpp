#include <bits/stdc++.h>
#include "edge.hpp"

using std::cin, std::cout, std::vector;

const int MAXN = 10; // max # of nodes
int n, m; // number of nodes and edges
vector<int> adj[MAXN]; // adjacency list
bool visited[MAXN]; // visited array

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++){ // for each of m edges
        int a, b;
        cin >> a >> b;
        a--; b--; // subtract 1 to maintain zero-indexing of vertices
        adj[a].push_back(b);
        adj[b].push_back(a); // omit this line if the graph is directed
    }
    return 0;
}