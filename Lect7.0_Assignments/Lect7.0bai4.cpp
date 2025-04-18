#include<iostream>
using namespace std;
int luyThua(int x, int n){ // tính lũy thừa
	if(n == 0)return 1; // trường hợp cơ sở :  nếu n = 0 thì return 1
	return x* luyThua(x,n-1); // gọi đệ quy
}
int main(){
	int x;
	int n;
	cin >> x >> n;
	cout << luyThua(x,n);
	return 0;
}