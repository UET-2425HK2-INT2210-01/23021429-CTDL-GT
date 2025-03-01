#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *prev;
	Node *next;
	Node(int x){
		data = x;
		next = nullptr;
		prev = nullptr;
	}
};
class doubleLinkedList{
	public:
		Node *head = nullptr;
		Node *last = nullptr;
		int len = 0;
		void duyet(Node *head){
		    Node *temp = head;
			while(temp != nullptr){
				cout << temp -> data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		void insert(int x){
			Node *newNode =  new Node(x);
			if(len == 0){
				head = newNode;
			}else{
				Node* temp= head;
				for(int i = 0; i < len-1;i++){
					temp = temp -> next;
				}
				newNode->prev = temp;
				newNode->next = nullptr;
				temp->next = newNode;
				last = newNode;
			}
			len++;
		}
		void count(){
			int count = 0;
			Node* temp = head;
			temp = temp -> next;
			while(temp != last){
				Node *temp1 = temp->prev;
				Node *temp2 = temp->next;
				if((temp->data  + temp1->data + temp2->data)== 0){
					count++;
				}
				temp = temp->next;
			}
			cout << count << endl;
		}
};
int main(){
	int n;
	cin >> n;
	int x;
	doubleLinkedList list;
	for(int i = 0; i < n; i++){
		cin >> x;
		list.insert(x);
	}
	list.count();
	return 0;
}
