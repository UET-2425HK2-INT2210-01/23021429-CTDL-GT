#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, X ;
	cin >> n >> X;
	vector<int> A(n); 
	for(int i = 0; i < n;i++){
		cin >> A[i];
	}
	vector<bool>dp(X+1, false); // khởi tạo mảng với X+1 phần tử và khởi đầu bằng false
	dp[0] = true; // luôn có tổng  = 0  nên dp[0] = true
	for(int i = 0 ; i < n; i++){ // duyệt qua từng i
		for(int j = X; j >= A[i]; j--){ // duyệt qua từng giá trị từ lớn tới nhỏ
			if(dp[j - A[i]]) dp[j] = true; // nếu đã tạo được tổng trước đó 
			// có thể thêm A[i] vào , và tạo tổng j
		}
	}
	if(dp[X]) cout << "YES";
	else cout << "NO";
	return 0;
}