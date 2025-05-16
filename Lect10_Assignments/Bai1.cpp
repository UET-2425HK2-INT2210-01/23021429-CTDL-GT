#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
bool visited[1001];
 void dfs(int u){ // hàm duyệt theo chiều sâu
 	visited[u] = true; // đánh dấu đỉnh đã thăm là true
 	for(int x : adj[u]){ // duyệt các đỉnh kề đỉnh u
 		if(!visited[x]){ // nếu chưa thăm thì gọi đệ quy
 			dfs(x);
		 }
	 }
 }
  void connectedComponent(){
  	int count = 0; // tạo biến đếm
  	memset(visited , false , sizeof(visited)); // khởi tạo tất cả là false
  	for(int i = 1; i <= n ;i++){
  		if(!visited[i]){ 
  			count++;
  			dfs(i);
		  }
	  }
	  cout << count;
}
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ;i++){
	int x,y;
	cin >> x >> y; // chuyển từ danh sánh cạnh sang danh sách kề
	adj[x].push_back(y);
	adj[y].push_back(x); // vì đây là đồ thị vô hướng
}
connectedComponent();
return 0;
}
