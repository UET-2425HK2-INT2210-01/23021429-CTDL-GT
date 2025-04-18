#include<iostream>
using namespace std;

int Fibonacci(int n){  // hàm tính số Fibonacci
	if(n == 1 ) return 1; // trường hợp cơ sở : nếu n = 1 thì return 1
	if (n == 0) return 0;// nếu n = 0 thì return 0
	return  Fibonacci(n-1) + Fibonacci(n-2); // gọi đệ quy
}
int main(){
	int n;
	cin >> n;
	cout << Fibonacci(n);
	return 0;
}