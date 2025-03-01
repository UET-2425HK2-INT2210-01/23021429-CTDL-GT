#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Queue {
public:
    Node* head = nullptr;

    void duyet() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if(head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void dequeue() {
        if(head == nullptr) {
            return;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;
    string operat;
    int x;
    Queue queue;

    for(int i = 0; i < n; i++) {  
        cin >> operat; 
        if(operat == "enqueue") {
            cin >> x;
            queue.enqueue(x);
        } else {
            queue.dequeue();
        }
    }

    queue.duyet();
    return 0;
}

