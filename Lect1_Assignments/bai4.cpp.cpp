#include <bits/stdc++.h>
using namespace std;
 void Sort(int a[], int n){
 for(int i=0; i < n; i++){
 	for(int j = 0; j < n-1; j++){
 		if(a[j] > a[j+1]){
 			int temp = a[j];
 			a[j]= a[j+1];
 			a[j+1] = temp;
		 }
	 }
 }
 
}
 

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
    	cin >> a[i];
	}
	Sort(a,n);
	for(int i = 0 ; i < n ;i++){
		cout << a[i];
	}
	return 0 ;
}


