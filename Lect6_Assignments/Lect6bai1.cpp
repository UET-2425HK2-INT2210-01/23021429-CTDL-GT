#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node cho BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Lớp BST để quản lý cây
class BST {
public:
    Node* root;

    // Hàm chèn node (đệ quy)
    Node* insert(Node* node, int value) {
        if (node == nullptr) {// nếu rỗng thì thêm node mới
            return new Node(value);
        }
        if (value < node->data) { //nếu value bé hơn thì thêm bên trái
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value); // nếu value lớn hơn thì thêm bên phải
        } 
        return node;
    }

    // Hàm tìm node nhỏ nhất trong cây con bên phải (dùng khi xóa)
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left; // duyệt đến node con cuối cùng bên trái nhỏ nhất
        }
        return node;
    }

    // Hàm xóa node (đệ quy)
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) { // duyệt cây con bên trái
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value); // duyệt cây con bên phải
        } else {
            // Trường hợp 1: Node lá
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Trường hợp 2: Node có 1 con
            if (node->left == nullptr) {// xóa con bên phải
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {// xóa con bên trái
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Trường hợp 3: Node có 2 con
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Hàm duyệt Inorder và in trực tiếp dưới dạng mảng 
    void inorderToArray(Node* node, bool& isFirst) {
        if (node != nullptr) {
            inorderToArray(node->left, isFirst);
            // In giá trị của node
            if (isFirst) {
                cout << node->data;
                isFirst = false;
            } else {
                cout << ", " << node->data;
            }
            inorderToArray(node->right, isFirst);
        }
    }

    // Hàm in cây theo thứ tự Inorder (đệ quy)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }


    BST() {
        root = nullptr;
    }

    // Hàm chèn giá trị
    void insert(int value) {
        root = insert(root, value);
    }

    // Hàm xóa giá trị
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    // Hàm in cây dưới dạng mảng (dùng Inorder, không dùng vector)
    void printAsArray() {
        cout << "[";
        bool isFirst = true; // Biến để kiểm soát dấu phẩy
        inorderToArray(root, isFirst);
        cout << "]" << endl;
    }

    // Hàm in cây theo Inorder
    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // 1. Tạo BST từ danh sách ban đầu: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int value : initialValues) {
        tree.insert(value);
    }

    // 2. Thêm các giá trị: 14, 0, 35
    tree.insert(14);
    tree.insert(0);
    tree.insert(35);
   tree.printAsArray();

    // 3. Xóa các giá trị: 6, 13, 35
    tree.deleteNode(6);
    tree.deleteNode(13);
    tree.deleteNode(35);
    tree.printAsArray();

    // In kết quả cuối cùng theo thứ tự Inorder (phần này có trong code gốc)
    tree.printInorder();

    return 0;
}