#include<iostream>
using namespace std;

int GCD(int x, int y){
	if(y == 0)return x;
	return GCD(y,x%y);
}
int main(){
	int x;
	int y;
	cin >> x;
	cin >> y;
	cout << GCD(x,y);
	return 0;
	
}