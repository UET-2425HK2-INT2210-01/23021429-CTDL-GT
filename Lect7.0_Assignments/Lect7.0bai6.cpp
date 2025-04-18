#include<iostream>
using namespace std;
 int sum(int n){ // tính tổng các chữ số trong 1 số nguyên
 	if(n == 0)return 0; // trường hợp cơ sở nếu n = 0 thì return 0
 	return (n%10) + sum(n/10); // gọi đệ quy
 }
 int main(){
 	int n;
 	cin >> n;
 	cout << sum(n);
 	return 0;
 }