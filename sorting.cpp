/*
QUICK SORT
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pivotindex = partition(arr, low, high);
        qs(arr, low, pivotindex - 1);
        qs(arr, pivotindex + 1, high);
    }
}
void quicksort(vector<int> arr){
    qs(arr, 0, arr.size()-1);
}




SELECTION SORT
hum bache hue array me minimum elemebt dhudte h and use sabse aage kr dete h 
vector<int>a = {1,2,5,3,5,3};
        int n = a.size();
        for(int i = 0; i<n; i++){
            int miniindex = i;
            for(int j = i+1; j<n; j++){
                if(a[j] < a[miniindex]){
                    miniindex = j;
                }
            }
            swap(a[miniindex], a[i]);
        }
        for(int i:a){
            cout << i << " ";
        }
MERGE SORT  O(NlogN)
vector<int> a(100010);
void merge(int l, int r, int mid){
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    vector<int>L(l_sz), R(r_sz);
    for(int i =0; i< l_sz; i++){
        L[i] = a[i+l];
    }
    for(int i = 0; i<r_sz; i++){
        R[i] = a[i+mid+1];

    }
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0, r_i = 0;
    for(int i =l; i<=r; i++){
        if(L[l_i] <= R[r_i]){
            a[i] = L[l_i];
            l_i++;
        }
        else{
            a[i] = R[r_i];
            r_i++;
        }

    }

    
}
void mergeSort(int l, int r){
    if(l == r) return;
    int mid = (l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    merge(l, r, mid); 
}



BUBBLE SORT
vector<int>a = {2,5,3,5,3,5,32,45};
        int n = a.size();
        for(int i = n-1; i>= 0; i--){
            bool didswap = false;
            for(int j = 0; j<n-1; j++){
                if(a[j] > a[j+1]){
                    int temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
                    didswap = true;
                }
            }
            if(didswap == false){
                break; 
                
            }
        }
        for(int i:a){
            cout << i << " ";
        }

INSERTION SORT
vector<int>a = {2,3,5,2,4,2,4,2};
        int n = a.size();
        for(int i = 0; i<n; i++){
            int j = i;
            while(j > 0 && a[j-1] > a[j]){
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                j--;
            }
        }
        for(int i:a){
            cout << i << " ";
        }
SHELL SORT
int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    { 
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            arr[j] = temp;
        }
    }
    return 0;
}

HEAP SORT
void heapify(vector<int> &arr, int n, int i){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < n && arr[smallest] > arr[left]){
            smallest = left;


        }
        if(right < n && arr[smallest] > arr[right]){
            smallest = right;
        }
        if(smallest != i){
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest);
        }
}



vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for(int i = n/2 -1; i>= 0; i--){
        heapify(arr, n, i);
    }
    return arr;
}


void heapsort(vector<int> arr, int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}









*/