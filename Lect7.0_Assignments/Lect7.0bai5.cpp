#include<iostream>
using namespace std;
int count(int n){ // đếm chữ số trong 1 số nguyên
	if(n == 0)return 0 ; // trường hợp cơ sở : nếu n = 0 return 0
	return 1 + count(n/10); // gọi đệ quy
}
int main(){
	int n ;
	cin >> n;
	cout << count(n);
	return 0;
}