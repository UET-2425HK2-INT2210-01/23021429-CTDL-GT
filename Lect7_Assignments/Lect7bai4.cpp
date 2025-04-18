#include<iostream>
#include<vector>
using namespace std;

void print_path(	vector<int>path){
	for(int i = 0; i < path.size();i++){
		cout << path[i];
	}
	cout << endl;
}
void generate_binary(int n , int current , vector<int>path){
	if(current == n){
	    print_path(path);
	    return;
	}
	else{
		for(int i = 0 ; i <=1 ;i++){
			path.push_back(i);
			generate_binary(n , current+ 1, path);
			path.pop_back();
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<int>path;
	generate_binary(n, 0 ,path);
	return 0;
}