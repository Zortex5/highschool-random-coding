#include <iostream>
#include <vector>

using namespace std;

int distanceToLeaf(int n, int p, vector<int> (&graph)[]) {
    if (graph[n].size() == 1) return 0;

    int maxDist = 0;
    for (int next : graph[n]) {
        maxDist = max(maxDist, 1 + distanceToLeaf(next, n, graph));
    }

    return maxDist;
}

int maxDistance(int n, int p, vector<int> (&graph)[]) {
    int maxDist = 0;
    int secondMaxDist = 0;
    for (int next : graph[n]) {
        if (next == p) continue;

        int dist = distanceToLeaf(next, n, graph);
        maxDist = max(maxDist, dist);
        if (dist != maxDist) {
            secondMaxDist = max(secondMaxDist, dist);
        }
    }

    return maxDist + secondMaxDist;
}

int treeDiameter(vector<int> (&graph)[]) {
    return maxDistance(1, 0, graph) + 2;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> graph[n + 1];
    int distancesToLeaf[n + 1];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << treeDiameter(graph) << endl;
}