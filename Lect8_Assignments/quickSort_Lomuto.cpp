#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& vec , int low ,int high){
	int pivot = vec[high];//  chọn pivot là phần tử cuối
	int i =  low-1; 
	for(int j = low; j<= high-1;j++){ // duyệt từ đầu đến cuối mảng
		if(vec[j] <= pivot){ // nếu phần tử tại j nhỏ hơn hoặc bằng pivot
			i++; // tăng i
			swap(vec[i],vec[j]); // hoán đổi 
		}
	}
	swap(vec[i+1],vec[high]); // đổi pivot về đúng vị trí
	return(i+1); // trả về vị trí đúng của pivot
}
void quickSort(vector<int>& vec, int low, int high){
	if(low < high){ // nếu mảng có ít nhất 2 phần tử
		int pi = partition(vec, low, high);
		quickSort(vec, low, pi -1); // sắp xếp phần bên trái pivot
		quickSort(vec, pi+ 1, high); // sắp xếp phần bên phải pivot
	}
}
int main(){ // hàm main chính 
	vector<int> vec ={3,5,2,2,1,8};
	int n = vec.size();
	quickSort(vec , 0 , n - 1);
	for(int i = 0; i < n ; i++){
		cout << vec[i] <<" ";
	}
	return 0;
	}
