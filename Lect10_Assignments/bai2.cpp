#include <bits/stdc++.h>
using namespace std;

int n, m, X, Y;
vector<int> adj[1001];
int dist[1001]; // mảng lưu khoảng cách từ X đến các đỉnh

void input() {
    cin >> n >> m >> X >> Y;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // vì là đồ thị có hướng
    }

    // Khởi tạo khoảng cách ban đầu là -1 (chưa đến được)
    memset(dist, -1, sizeof(dist));
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front(); // đưa u vào đầu danh sách 
        q.pop(); // xóa nó

        for (int v : adj[u]) { // duyệt các đỉnh kề với u
            if (dist[v] == -1) { // nếu v chưa được thăm
                dist[v] = dist[u] + 1; // cập nhật số cạnh
                q.push(v); // đưa v vào hàng đợi và tiếp tục duyệt
            }
        }
    }
}

int main() {
    input();
    bfs(X);

    cout << dist[Y] << endl; // in ra số cạnh từ X đến Y (nếu không đến được thì sẽ là -1)
    return 0;
}
