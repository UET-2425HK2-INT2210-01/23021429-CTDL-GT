#include <iostream>
using namespace std;
const int NODES_SIZE = 100;// mảng chứa các nút

struct Node {
    int data;
    Node* firstChild; // nốt gốc
    Node* sibling;// anh chị em
    
    Node(int d) {// constructor
        data = d;
        firstChild = nullptr;
        sibling = nullptr;
    }
};

class Tree {// lớp tree để quản lí và thao tác trên cây
private:
    Node* root;// con trỏ trỏ tới nút gốc của cây
    Node* nodeList[NODES_SIZE];// mảng lưu danh sách các Node
    bool isChild[NODES_SIZE]; // mảng đánh dấu xem có phải con của các nốt khác không

public:
    Tree() { // constructor của lớp Tree
        root = nullptr;
        for (int i = 0; i < NODES_SIZE; i++) {
            isChild[i] = false; // ban đầu không nút nào là con của nút khác
            nodeList[i] = nullptr; //khởi tạo các nút trong danh sách là nullptr
        }
    }

    void addChild(int parent, int child) { // hàm thêm các con 
        if (parent == child) { // parent và child không được trùng nhau
            cout << "error";
            return;
        }
        if (!nodeList[parent]) { // thêm nút parent nếu chưa tồn tại
            nodeList[parent] = new Node(parent); 
        }
        if (!nodeList[child]) { // thêm nút child nếu chưa tồn tại
            nodeList[child] = new Node(child); 
        }
        Node* parentNode = nodeList[parent]; // lấy con trỏ tới nút parent
        Node* childNode = nodeList[child]; // lấy con trỏ tới nút child
        if (!parentNode->firstChild) { // nếu parent chưa có con đầu tiên
            parentNode->firstChild = childNode; //thì gán childNode làm con đầu tiên 
        } else {
            Node* temp = parentNode->firstChild; // khởi tạo biến tạm
            while (temp->sibling != nullptr) { //duyệt đến anh chị em cuối cùng
                temp = temp->sibling; 
            }
            temp->sibling = childNode; // gán chileNode vào anh chị em cuối cùng
        }
        isChild[child] = true; // đánh dấu child là con của nút khác
    }

    void findRoot(int N) {// hàm tìm gốc
        for (int i = 1; i <= N; i++) { 
            if (!isChild[i] && nodeList[i]) { // nếu nút i không phải con của nút nào thì gán nút i làm gốc
                root = nodeList[i];
                return;
            }
        }
        root = nullptr; 
    }

    int getHeight(Node* root) {// hàm tính chiều cao của cây
        if (!root) return -1; // nếu nút rỗng thì chiều cao là -1;
        int maxChildHeight = -1; // khởi tạo chiều cao lớn nhất của các cây con;
        Node* temp = root->firstChild; // gán temp bắt đầu từ con đầu tiên
        while (temp) { // duyệt qua tất cả các con gồm firstchild và sibling
            maxChildHeight = max(maxChildHeight, getHeight(temp)); // tính chiều cao lớn nhất
            temp = temp->sibling;
        }
        return maxChildHeight + 1; // chiều cao của cây bằng chiều cao lớn nhất của con + 1
    }

    void preorder(Node* root) { // hàm preorder
        if (root == nullptr) return; // nếu gốc rỗng thì không làm gì
        cout << root->data << " "; // in giá trị của nút hiện tại
        Node* child = root->firstChild; // bắt đầu từ con đầu tiên
        while (child) { // duyệt tất cả các con
            preorder(child); // gọi hàm đệ quy 
            child = child->sibling;
        }
    }

    void postorder(Node* node) { // hàm postorder
        if (node == nullptr) return; 
        Node* child = node->firstChild;
        while (child) {
            postorder(child); // gọi hàm đệ quy
            child = child->sibling;
        }
        cout << node->data << " "; 
    }

    bool isBinary(Node* root) { // hàm kiểm tra xem có phải cây nhị phân
        if (root == nullptr) return true;
        int count = 0; // khởi tạo biến đếm
        Node* child = root->firstChild;
        while (child) { // duyệt tất cả các con
            count++; // tăng biến đếm
            child = child->sibling; // chuyển sang anh chị em tiếp theo
        }
        if (count > 2) return false; // nếu số con lớn hơn 2 , không phải cây nhị phân
        Node* sibling = root->firstChild; //bắt đầu từ con đầu tiên
        while (sibling) { 
            if (!isBinary(sibling)) return false; // kiểm tra đệ quy các con
            sibling = sibling->sibling;
        }
        return true; // tất cả hợp lệ trả về true
    }

    void inorder(Node* root) { // hàm inorder
        if (root == nullptr) return;
        if (!isBinary(root)) {
            cout << "NOT BINARY TREE" << " ";
            return;
        }
        Node* left = root->firstChild; // con trái là con đầu tiên
		Node* right = nullptr; // con phải là anh chị em
			if (left) {
			    right = left->sibling;
			}
        inorder(left); // gọi hàm đệ quy con bên trái
        cout << root->data << " ";
        inorder(right); // gọi hàm đệ quy con bên phải
    }

    void duyet(int N) {// hàm duyệt
        findRoot(N);// tìm gốc
        if (!root) {
            cout << "No root found!\n";
            return;
        }
        cout << getHeight(root) << endl; // in chiều cao 
        preorder(root); cout << endl;// in kết quả duyệt preorder 
        postorder(root); cout << endl;// 
        inorder(root); cout << endl;//
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Tree tree; // tạo một cây mới
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // nhập cạnh u v , u là cha của v;
        tree.addChild(u, v); // thêm cạnh vào cây
    }
    tree.duyet(n); // xử lí và in kết quả
    return 0;
}