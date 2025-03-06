#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

class Stack{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void duyet(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void push(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            Node* tmp = tail;
            tmp->next = newNode;
            tail = newNode;
            tail->prev = tmp;
        }
    }

    void pop(){
        Node* tmp = tail;
        if(tmp == nullptr){
            return;
        }else{
            tail = tmp->prev;
            tail->next = tmp->next;
            delete tmp;
        }
    }
};

int main(){
    int n;
    cin >> n;
    string operat;
    int x;
    Stack stack;
    for(int i = 1; i <= n; i++){
        cin >> operat;
        if(operat == "push"){
            cin >> x;
            stack.push(x);
        }else{
            stack.pop();
        }
    }
    stack.duyet();
    return 0;
}
/* pseudo codes:
cau truc node:
    du lieu
    con tro prev
    con tro next

ham tao node(x):
    gan du lieu = x
    gan prev = null
    gan next = null

lop stack:
    head = null
    tail = null

    ham duyet():
        tmp = head
        lap khi tmp khac null:
            in tmp du lieu
            tmp = tmp next
        in xuong dong

    ham push(x):
        tao newNode(x)
        neu head = null:
            gan head = newNode
            gan tail = newNode
        nguoc lai:
            tmp = tail
            tmp next = newNode
            tail = newNode
            tail prev = tmp

    ham pop():
        tmp = tail
        neu tmp = null:
            ket thuc
        nguoc lai:
            tail = tmp prev
            tail next = tmp next
            xoa tmp

ham main():
    nhap n
    stack
    lap i tu 1 den n:
        nhap operat
        neu operat = "push":
            nhap x
            stack push(x)
        nguoc lai:
            stack pop()
    stack duyet()
*/
do phuc tap thuat toan : O(n)

