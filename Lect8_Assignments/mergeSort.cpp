#include <bits/stdc++.h>
using namespace std;
// hàm merge gộp hai mảng con thành một mảng sắp xếp
void merge(vector<int>& arr, int left,  int mid, int right) 
{
    int n1 = mid - left + 1; // kích thước mảng con trái
    int n2 = right - mid; // kích thước mảng con phải

    vector<int> L(n1), R(n2); // tạo mảng tạm để lưu 2 mảng con 

    for (int i = 0; i < n1; i++) // sao chép dữ liệu từ mảng chính vào mảng tạm
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0; // chỉ số để duyệt mảng L , R
    int k = left; // chỉ số để ghi vào mảng chính
 // so sánh và gôp hai mảng con
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { // nếu phần tử ở L nhỏ hơn phần tử ở R 
            arr[k] = L[i]; // ghi phần tử ở L vào mảng
            i++; //tăng chỉ số của L
        }
        else {
            arr[k] = R[j]; // ghi phần tử của R
            j++; // tăng chỉ số của R
        }
        k++; // tăng chỉ số của arr
    }

    while (i < n1) {// ghi các phần tử còn lại của L vào arr
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) { // ghi các phần tử còn lại của R vào arr
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; // tính chỉ số giữa để chia mảng 
    mergeSort(arr, left, mid);// sắp xếp đệ quy mảng trái 
    mergeSort(arr, mid + 1, right); // sắp xếp đệ quy mảng phải
    merge(arr, left, mid, right); // gộp hai mảng con đã sắp xếp 
}

void printVector(vector<int>& arr) // hàm in ra mảng
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
 // hàm main chính
int main()
{
    vector<int> arr = { 3,5,2,2,1,8 };
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    printVector(arr);
    return 0;
}
