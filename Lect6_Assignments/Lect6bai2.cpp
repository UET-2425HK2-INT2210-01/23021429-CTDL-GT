#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;
    // xác định chỉ số cha , con trai , con phải tại chỉ số i
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }
    //hàm dùng sau khi xóa phần tử để khôi phục max-heap
    void heapifyDown(int i) {
        int largest = i;
        int l = left(i), r = right(i);
// so sánh node hiện tại với hai con, nếu có con lớn hơn thì hoán đỏir và đệ quy 
        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) { // dùng khi thêm phần tử vào cuối heap
    // so sánh với cha , nếu lớn hơn thì tiếp tục đi lên
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
// tạo ra một heap từ danh sách sẵn các số nguyên
    MaxHeap(const vector<int>& values) {
        for (int val : values) {
            insert(val);
        }
    }
//
    void insert(int val) {
        heap.push_back(val);// thêm vào cuối mảng 
        heapifyUp(heap.size() - 1);//đưa phần tử về đúng vị trí bằng cách chèo lên
    }

    bool deleteValue(int val) {
    	// tìm vị trí phần tử cần xóa
        int index = -1; 
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -1) return false;
// thay thế nó bằng phần tử cuối rồi pop back
        heap[index] = heap.back();
        heap.pop_back();
//gọi heapidyUp và heapifyDown  để khôi phục hep
        if (index < heap.size()) {
            heapifyUp(index);
            heapifyDown(index);
        }

        return true;
    }

    void printHeap() { // in heap
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    vector<int> initial = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    MaxHeap heap(initial);
    heap.printHeap();
    
    heap.insert(14);
    heap.insert(0);
    heap.insert(35);
    heap.printHeap();

    heap.deleteValue(6);
    heap.deleteValue(13);
    heap.deleteValue(35);
    heap.printHeap();

    return 0;
}
