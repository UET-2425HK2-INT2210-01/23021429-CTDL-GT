#include <iostream>
#include <vector>
using namespace std;

// Hàm phân vùng Hoare
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[low]; // Chọn pivot là phần tử đầu tiên
    int left = low + 1;   // Con trỏ trái bắt đầu từ phần tử sau pivot
    int right = high;     // Con trỏ phải bắt đầu từ phần tử cuối

    while (true) {
        // Tìm phần tử lớn hơn pivot từ bên trái
        while (left <= high && vec[left] <= pivot) {
            left++;
        }
        // Tìm phần tử nhỏ hơn pivot từ bên phải
        while (right >= low && vec[right] > pivot) {
            right--;
        }
        // Nếu left vượt qua right, dừng
        if (left > right) {
            break;
        }
        // Hoán đổi vec[left] và vec[right]
        swap(vec[left], vec[right]);
    }

    // Hoán đổi pivot (vec[low]) với vec[right] để đặt pivot vào đúng vị trí
    swap(vec[low], vec[right]);

    return right; // Trả về điểm chia
}

// Hàm Quicksort
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) { // Kiểm tra trước khi gọi partition
        // Tìm điểm chia
        int pi = partition(vec, low, high);
        // Gọi đệ quy trên hai phần
        quickSort(vec, low, pi - 1); // Phần bên trái
        quickSort(vec, pi + 1, high); // Phần bên phải
    }
}

// Chương trình chính
int main(){
	vector<int> vec ={3,5,2,2,1,8};
	int n = vec.size();
	quickSort(vec , 0 , n - 1);
	for(int i = 0; i < n ; i++){
		cout << vec[i] <<" ";
	}
	cout << endl;
	return 0;
	}