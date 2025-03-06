#include<iostream>
using namespace std;
int a[10000];
int maxN = 10000;
int n =0;
void push(int x){
	if(n == maxN){
		return;
	}
	a[n] = x; n++;
}
void pop(){
	if(n == 0){
		return;
	}else{
		for(int i = 0; i < n-1;i++){
			a[i] = a[i+1];
		}
		--n;
	}
}
int main(){
	 int n;
	 cin >> n;
	 int x;
	 string operat;
	 for(int i = 0; i < n; i++){
	 	cin >> operat;
	 	if(operat == "push"){
	 		cin >> x;
	 		push(x);
		 }
		 if(operat == "pop")
		 	pop();
		 }
	   for(int i = 0; i < n; i++){
	   	cout << a[i] <<" ";
	   }
	   return 0;
	 }
	 
	/* pseudo codes:
Bat dau chuong trinh
    Khai bao mang a co kich thuoc 10000
    Khai bao bien maxN = 10000
    Khai bao bien n = 0 (de theo doi so phan tu hien co trong hang doi)

    Ham PUSH(x):
        Neu n da dat maxN thi thoat
        Dua x vao vi tri a[n]
        Tang n len 1 don vi

    Ham POP():
        Neu n == 0 (hang doi rong) thi thoat
        Dich chuyen tat ca phan tu len mot vi tri (a[i] = a[i+1])
        Giam n di 1 don vi
        
    Trong ham MAIN():
        Nhap so luong thao tac can thuc hien (operations)
        Lap tu 0 den operations-1:
            Nhap chuoi thao tac (operat)
            Neu thao tac la "push":
                Nhap gia tri x
                Goi ham PUSH(x)
            Neu thao tac la "pop":
                Goi ham POP()

        Lap i tu 0 den n-1:
            In a[i] ra man hinh

Ket thuc chuong trinh
-> độ phức tạp thuật toán : O(n()

