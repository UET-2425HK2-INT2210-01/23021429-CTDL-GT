#include<iostream>
using namespace std;

int sum(int n){ // hàm tính tổng từ 1 đến n
	if(n == 0 || n ==1)// trường hợp cơ sở  nếu n = 0 hoặc n = 1 thì return 1
	return 1; 
	return n + sum(n-1); // gọi đệ quy
}
int main(){
	int n; 
	cin >> n;
	cout << sum(n) << endl;
	return 0;
}