#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void swap(int & a, int &b) {// hàm đổi 
    int temp = a;
    a = b;
    b = temp;
}
void sort(vector<int> &a) {// hàm sắp xếp
    
    for(int i = 0; i < a.size() - 1; i++) {// vòng lặp
        for(int j = i + 1; j < a.size(); j++) {
            if(a[j] < a[i]) { 
                swap(a[i], a[j]); // gọi đệ quy
            }
        }
    }
}

int main() {
    // tạo file
    ifstream input("numbers.txt");
    ofstream output("number.sorted.txt");

    if(!input) {
        cout << "Failed" << endl;
        return 0;
    }
    vector<int> a; 
    
    int val;
    while(input.good()) {
        input >> val;
        a.push_back(val); // thêm các giá trị vào trong mảng
    }
    input.close();
    sort(a); // gọi hàm sort

    for(int i = 0; i < a.size() - 1; i++) {// int ra các giá trị
        output << a[i] << " ";
    }
    return 0;
}