#include <iostream>
#include <vector>
#include <stack>

using std::vector, std::stack, std::cout, std::cin;

int main() {
    int root, target;
    cin >> root >> target;
    int n, e;
    cin >> n >> e;

    vector<int> adjList[n];
    bool visited[n] = {false};
    stack<int> s;

    for (int i = 0; i < e; i++) {
        int parent, child;
        cin >> parent >> child;
        adjList[parent].push_back(child);
    }

    s.push(root);
    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (current == target) {
            cout << "Target Acquired\n";
            return 0;
        }

        for (int child : adjList[current]) {
            if (!visited[child]) {
                s.push(child);
                visited[child] = true;
            }
        }
    }

    cout << "Target Lost\n";
}