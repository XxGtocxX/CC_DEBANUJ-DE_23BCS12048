#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> forbidden(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        forbidden[a].insert(b);
        forbidden[b].insert(a);
    }

    // Find root (a node not forbidden with node 1)
    int root = -1;
    for (int i = 2; i <= n; i++) {
        if (forbidden[1].count(i) == 0) {
            root = i;
            break;
        }
    }

    cout << n - 1 << "\n";

    // Connect root with all nodes except itself
    for (int i = 1; i <= n; i++) {
        if (i == root) continue;
        cout << root << " " << i << "\n";
    }

    return 0;
}
