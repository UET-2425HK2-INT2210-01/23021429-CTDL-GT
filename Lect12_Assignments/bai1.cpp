#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n, m;
vector<int> adj[maxn];     // Danh sách kề
bool visited[maxn];        // Mảng đánh dấu đã thăm
vector<int> topo;          // Lưu thứ tự tô-pô

// Đọc dữ liệu đồ thị có hướng
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);  // Cạnh x → y
    }
    memset(visited, false, sizeof(visited));
}

// DFS để sắp xếp tô-pô
void dfs(int u) {
    visited[u] = true;
    for (int x : adj[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
    topo.push_back(u); // Sau khi thăm xong đỉnh u, đưa vào topo
}

int main() {
    input();
    // Gọi DFS cho từng đỉnh chưa thăm
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end()); // Đảo ngược để có thứ tự tô-pô đúng

    // In ra thứ tự tô-pô
    for (int x : topo) {
        cout << x << " ";
    }

    return 0;
}
