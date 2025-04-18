#include<iostream>
using namespace std;

int GCD(int x, int y){ // hàm đệ quy tìm UCLN
	if(y == 0)return x; // nếu y = 0 thì x là ước chung lớn nhất
	return GCD(y,x%y); // còn không thì gọi đệ quy
}
int main(){ // hàm main
	int x;
	int y;
	cin >> x;
	cin >> y;
	cout << GCD(x,y);
	return 0;
	
}