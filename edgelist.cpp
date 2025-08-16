#include <bits/stdc++.h>
#include "edge.hpp"

using std::sort, std::cin, std::cout, std::vector;

int n, m; // number of nodes and edges
vector<Edge> edges;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){ // for each of the m edges
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--; // subtract 1 to maintain zero-indexing of vertices
        edges.push_back(Edge(a, b, w)); // add edge to list
    }
    sort(edges.begin(), edges.end());
    return 0;
}