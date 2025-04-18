#include<iostream>
#include<vector>
using namespace std;

void print_path(vector<int>path){ // in ra kết quả
	for(int i = 0; i < path.size();i++){
		cout << path[i];
	}
	cout << endl;
}
void generate_binary(int n , int current , vector<int>path){// hàm đệ quy 
	if(current == n){ // nếu current = n thì in ra kết quả
	    print_path(path);
	    return;
	}
	else{
		for(int i = 0 ; i <=1 ;i++){ // vòng lặp chạy từ 0 đến 1
			path.push_back(i); // thêm phần tử i vào mảng
			generate_binary(n , current+ 1, path); // gọi đệ quy
			path.pop_back(); // xóa phần tử khỏi mảng
		}
	}
}
int main(){ // hàm main
	int n;
	cin >> n;
	vector<int>path;
	generate_binary(n, 0 ,path);
	return 0;
}