#include <iostream>
using namespace std;

int n; int stack[10000];

void push(int x){
	stack[n] = x;
	n++;
}
void pop(){
	if(n >= 1){
		--n;
	}
}
int top(){
	return stack[n-1];
}
int size(){
	return n;
}
int main(){
    int q;
    cin >> q; 

    while (q--) {
        string command;
        cin >> command;  

        if (command == "push") {
            int x;
            cin >> x;
            push(x);
        } 
        else if (command == "pop") {
            pop();
        } 
        else if (command == "top") {
            cout << top() << endl;
        } 
        else if (command == "size") {
            cout << size() << endl;
        }
    }
    return 0;
}
/*
khai bao bien n = 0
khai bao mang stack kich thuoc lon

ham push(x):
    stack[n] = x
    n = n + 1

ham pop():
    neu n > 0:
        n = n - 1

ham top():
    neu n > 0:
        tra ve stack[n-1]
    nguoc lai:
        tra ve -1

ham size():
    tra ve n

ham main():
    nhap q
    lap q lan:
        nhap thao tac
        neu thao tac la "push x":
            nhap x
            goi ham push(x)
        neu thao tac la "pop":
            goi ham pop()
        neu thao tac la "top":
            in ra top()
        neu thao tac la "size":
            in ra size()
*/
-> do phuc tap thuat toan :O(1)
