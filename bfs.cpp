#include <iostream>
#include <vector>
#include <queue>

using std::vector, std::queue, std::cout, std::cin;

int main() {
    int root, target;
    cin >> root >> target;
    int n, e;
    cin >> n >> e;

    vector<int> adjList[n];
    bool visited[n] = {false};
    queue<int> q;

    for (int i = 0; i < e; i++) {
        int parent, child;
        cin >> parent >> child;
        adjList[parent].push_back(child);
    }

    q.push(root);
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target) {
            cout << "Target Acquired\n";
            return 0;
        }

        for (int child : adjList[current]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
    }

    cout << "Target Lost\n";
}