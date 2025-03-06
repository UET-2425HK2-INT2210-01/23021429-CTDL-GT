#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int x){
		data = x;
		next = nullptr;
	}
};
class Queue{
	public:
		Node *head = nullptr;
	
	void duyet(){
		Node *temp = head;
		while(temp != nullptr){
			cout << temp -> data <<" ";
			temp = temp->next;
		}
	    cout << endl;
	}
	
	void enqueue(int x){
		Node* newNode = new Node(x);
		if(head == nullptr){
			head = newNode;
		}else{
			Node* temp = head;
			while(temp -> next !=nullptr){
				temp = temp -> next;
			}
			temp -> next = newNode;
		}
	}
	void dequeue(){
		if(head == nullptr){
			return;
		}else{
			Node* temp = head;
			head = head -> next;
			delete temp;
		}
	}
};
int main(){
	int n;
	cin >> n;
	int x;
	string operat;
	Queue queue;
	for(int i = 0; i < n; i++){
		cin >> operat;
		if(operat == "enqueue"){
			cin >> x;
			queue.enqueue(x);
		}else{
			queue.dequeue();
		}
	}
	queue.duyet();
	return 0;
}
/* pseudo codes:
    dinh nghia cau truc Node;
    data : so nguyen;
    next : con tro den Node tiêp theo;
    ham khoi tao x;
    gán data = x;
    gán next = nullptr;

dinh nghia lop queue:
    head: con tro den phan tu dau hang doi (ban dau la null)

    ham duyet():  duyet va in cac phan tu trong hang doi
        temp = head  
        trong khi temp khac null:
            in temp.data
            temp = temp.next
        in xuong dong

    ham enqueue(x):
        tao newnode voi gia tri x
        neu head == null:
            head = newnode
        nguoc lai:
            temp = head
            trong khi temp.next khac null:
                temp = temp.next 
            temp.next = newnode 

    ham dequeue():  
        neu head == null:
            tra ve
        nguoc lai:
            temp = head
            head = head.next 
            xoa temp  
            
chuong trinh chinh:
    nhap n  
    tao queue (hang doi)

    lap i tu 1 den n:
        nhap thao_tac
        neu thao_tac == "enqueue":
            nhap x
            goi queue.enqueue(x) 
        nguoc lai:
            goi queue.dequeue()  

    goi queue.duyet() 
*/
-> do phuc tap thuat toan O(n)
