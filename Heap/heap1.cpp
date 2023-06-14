#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size = 0;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int value){
        size = size + 1;
        int index = size;
        arr[index] = value;
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent; /// index ko update kr diya ab wo parent ko point kr rha hoga

            }
            else{
                return;
            }
        }
    }
    void deletefromheap(){
        if(size == 0){
            cout << "Nothing to delete\n";
            return;
        }
        // last and root ko swap kiya
        arr[1] = arr[size];
        size--;
        //take root to its correct position
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }

        }
    }
    void print(){
        for(int i = 1; i<= size; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    
    

};
void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;
        if(left <= n && arr[largest] < arr[left]){
            largest = left;


        }
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
}
void heapsort(int arr[], int n){  // nlogn     , first build heap , then heapsort
    int size = n;
    while(size > 1){
        // step 1;
        swap(arr[size], arr[1]);
        size--;


        // step 2
        heapify(arr, size, 1);
    }

}
 
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromheap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }
    
    cout << "printing the array now\n";
    for(int i = 1; i<= n; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
    heapsort(arr, n);
    cout << "printing after heapsort\n";
    for(int i = 1; i <=n; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
    // Priority queue  max heap hota h by default
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    cout << "element at top\n";
    cout << pq.top() << '\n'; 

    // min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(1);
    minheap.push(4);
    minheap.push(2);
    minheap.push(3);
    minheap.push(5);
    cout << "element at top of min heap\n";
    cout << minheap.top() << '\n';


}
