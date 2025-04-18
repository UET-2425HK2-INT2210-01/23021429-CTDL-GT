#include<iostream>
using namespace std;
 int daoNguoc(int n , int revNum = 0){ // hàm đảo ngược số nguyên n
 	if(n == 0)return revNum; // trường hợp cơ sở : n = 0 thì return revNum; 
 	return daoNguoc(n/10,revNum*10 + n%10 ); //gọi đệ quy
 }
 int main(){
 	int n;
 	cin >> n;
 	cout << daoNguoc(n) ;
 	return 0;
 }