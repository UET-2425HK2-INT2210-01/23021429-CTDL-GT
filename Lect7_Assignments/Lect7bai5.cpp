#include <iostream>
#include <vector>
using namespace std;

// Hàm in ra một hoán vị
void print_path(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
    }
    cout << endl;
}

// Hàm kiểm tra xem vector path có bị trùng phần tử hay không (tức là có phải hoán vị hợp lệ không)
bool isValid(const vector<int>& path) {
    for (int i = 0; i < path.size() - 1; i++) {
        for (int j = i + 1; j < path.size(); j++) {
            if (path[i] == path[j]) return false; // Nếu có phần tử trùng → không hợp lệ
        }
    }
    return true; // Nếu không có phần tử trùng → hợp lệ
}

// Hàm đệ quy sinh hoán vị
void hoanVi(int n, int count, vector<int> path) {
    // Nếu đã chọn đủ n phần tử, in ra kết quả
    if (count == n) {
        print_path(path);
        return;
    }

    // Duyệt tất cả các số từ 1 đến n để thử chèn vào vị trí tiếp theo
    for (int i = 1; i <= n; i++) {
        path.push_back(i); // Thêm số i vào đường đi (path)

        // Nếu path hiện tại là hợp lệ (không bị trùng số), thì tiếp tục đệ quy
        if (isValid(path)) {
            hoanVi(n, count + 1, path);
        }

        path.pop_back(); // Xoá phần tử cuối để quay lui 
    }
}

int main() {
    int n;
    cin >> n; 
    vector<int> path; 
    hoanVi(n, 0, path); 
    return 0;
}
