#include<iostream>
using namespace std;

int factorial(int n){ // tính giai thừa 
	if(n == 0 || n == 1){// trường hợp cơ sở : nếu n = 0 hoặc n = 1 return 1
		return 1;
	}
	return n * factorial(n-1); // gọi đệ quy
}
int main(){
	int n;
	cin >> n;
	cout << factorial(n);
	return 0;
}