#include<iostream>
#include<vector>
#include<algorithm> // dùng cho hàm max
using namespace std;

int main(){
	int n, X;
	cin >> n >> X;
	vector<int> weight(n), value(n);
	for(int i = 0; i < n ;i++){
		cin >> weight[i] >> value[i]; // trọng lượng và giá trị của đồ vật thứ i
	}
	vector<int>dp(X+1,0); // khởi tạo mảng với X+1 phần tử và khởi đầu tất cả bằng 0
	for(int i = 0; i < n ;i++){ // duyệt vòng lặp qua từng đồ vật i
		for(int x = X ; x >= weight[i]; x--){ // duyệt vòng lặp trọng lượng từ lớn tới nhỏ
			dp[x] = max(dp[x] ,dp[x - weight[i]]+value[i]); // nếu ta không chọn i thì giữ nguyên kết quả 
			// nếu ta chọn i thì giá trị dp[x - weight[i]] + value[i];
		}
	}
	cout << dp[X] << endl; // in ra giá trị tìm được
	return 0;
}