#include <bits/stdc++.h>
using namespace std;
double s(int n){
	if(n == 0){
		return 1;
	}else if( n > 0){
		return  2 * s(n-1);
	}else{
		n = -n;
		return 1/(2 * s(n -1));
	}
}
int main(){
	int n;
	cin >> n;
	cout << s(n) << endl;
	return 0;
}


/* pseudo-codes
 hàm s(n) :
 	nêu n = 0 
 	tra ve 1
 	neu n > 0
 	tra ve 2*s(n-1)
 	con neu n = -n hay n < 0;
 	tra ve 1/(2*s(n-1))
  ham main:
  	doc gia tri n
  	goi ham s(n) va in ra ket qua
  	-> do phuc tap thuat toan : O(n)
*/

double s1(int n){
	if(n == 0){
	  return 1;
	}else if( n > 0){
		return (1 << n);
	}else{
		n = -n;
		return (double) 1/(1 << n);
	}
}
int main(){
	int n;
	cin >> n;
	cout << s1(n) << endl;
	return 0;
}

/*pseudo-codes
  hàm double s1(n);
  neu n = 0
  tra ve 1;
  neu n > 0
  tra ve 2^n
  con neu n = -n hay n < 0
  tra ve 1/2^n;
  hàm main:
  doc gia tri n;
  goi ham s1(n) va in ra ket qua
  -> do phuc tap thuat toan : O(1)

