#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int len = 0;

    LinkedList() {
        head = nullptr;
    }

    void insert(int p, int x) {
        if (p < 0 || p > len) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < p - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        len++;
    }

    void remove(int p) {
        if (p < 0 || p >= len || head == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* temp = head;
        if (p == 0) {
            head = head->next;
            delete temp;
        } else {
            Node* prev ;
            for (int i = 0; i < p-1; i++) {
                temp = temp->next;
            }
            prev = temp->next;
            temp->next=temp ->next->next;
            delete prev;
        }
        len--;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (op == "delete") {
            int p;
            cin >> p;
            list.remove(p);
        }
    }
    list.print();
    return 0;
}

