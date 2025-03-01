#include <iostream>
using namespace std;
int UCLN( int a, int b){
	while(b!= 0){
		int temp = b;
		b = a % b;
		a= temp;
	}
	return a;
}
int main(){
	int a,b;
	cin >> a >> b;
	cout << UCLN(a,b) << endl;
	return 0;
}

