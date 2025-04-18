#include <iostream>
#include <vector>
using namespace std;

void print_path( vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] ;
    }
    cout << endl;
}

bool isValid(const vector<int>& path) {
    for (int i = 0; i < path.size() - 1; i++) {
        for (int j = i + 1; j < path.size(); j++) {
            if (path[i] == path[j]) return false;
        }
    }
    return true;
}
void hoanVi(int n, int count, vector<int> path) {
    if (count == n) {
        print_path(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        path.push_back(i);

        if (isValid(path)) {
            hoanVi(n, count + 1, path);
        }

        path.pop_back(); 
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> path;
    hoanVi(n, 0, path);
    return 0;
}
