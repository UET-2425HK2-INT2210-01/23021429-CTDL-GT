#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Cấu trúc cạnh gồm 2 đỉnh và trọng số
struct edge {
    int u, v;
    int w;
};

const int maxn = 1001;
int n, m;
int parent[maxn], size[maxn];
vector<edge> canh;

// Khởi tạo mỗi đỉnh là một tập hợp riêng
void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

// Tìm đại diện của tập hợp chứa đỉnh v (có nén đường đi)
int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

// Hợp nhất 2 tập hợp, trả về false nếu đã cùng tập
bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    return true;
}

// Đọc dữ liệu từ bàn phím
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edge e = {x, y, w};
        canh.push_back(e);
    }
}

// So sánh hai cạnh theo trọng số (sắp xếp tăng dần)
bool cmp(edge a, edge b) {
    return a.w < b.w;
}

// Thuật toán Kruskal tìm cây khung nhỏ nhất và ghi ra file
void kruskal() {
    ofstream fout("connection.out");
    vector<edge> mst; // Lưu cạnh thuộc cây khung nhỏ nhất
    int d = 0;        // Tổng trọng số

    sort(canh.begin(), canh.end(), cmp); // Sắp xếp cạnh theo trọng số

    for (int i = 0; i < m; i++) {
        if (mst.size() == n - 1) break;  // Đủ n - 1 cạnh thì dừng
        edge e = canh[i];
        if (Union(e.u, e.v)) {          // Nếu thêm cạnh không tạo chu trình
            mst.push_back(e);
            d += e.w;
        }
    }

    if (mst.size() == n - 1) {          // Nếu tìm được cây khung
        fout << d << endl;
        for (auto it : mst) {
            fout << it.u << " " << it.v << " " << it.w << endl;
        }
    }
    fout.close();
}

int main() {
    input();
    make_set();
    kruskal();
}
